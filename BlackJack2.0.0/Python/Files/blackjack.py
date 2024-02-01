import os
import random
import pyglet
from maker import maker
from tkinter import *
from tkinter import messagebox
from typing import *
from db import DataBase


class Game_Screen:
    def __init__(self) -> None:
        """
        ### Black Jack 게임 실행 Class
        """
        self.screen = Tk()
        self.screen.title("Black Jack 2.0.0")
        self.set_screen_size()
        self.maker = maker(self.screen)
        self.python_path = os.path.join(os.getcwd())
        self.rank_db = DataBase()
        self.add_font()
        self.menu_screen()
        self.screen.mainloop()

    def game_setting(self) -> None:
        """
        게임 진행을 위한 변수 세팅 함수
        """
        self.card_loc = [294, 513, 732, 950]
        self.new_card = ["B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "B11", "B12", "B13", 
                           "R1", "R2", "R3", "R4", "R5", "R6", "R7", "R8", "R9", "R10", "R11", "R12", "R13"]
        self.card_piles = []

    def set_screen_size(self) -> None:
        """
        ### 화면 크기 및 위치 설정 함수
        """
        screen_width = 1204
        screen_height = 704
        windows_width = self.screen.winfo_screenwidth()
        windows_height = self.screen.winfo_screenheight()
        center_width = (windows_width - screen_width)//2
        center_height = (windows_height - screen_height)//2
        self.screen.geometry(f"{screen_width}x{screen_height}-{center_width}-{center_height}")
        self.screen.resizable(width=False, height=False)

    def img_path(self, path:str) -> str:
        """
        ### 이미지 경로 지정 함수
        path : 이미지 파일 경로 (Images 파일 하위 경로만)
        """
        return os.path.join(self.python_path, f"../../images/{path}")

    def add_font(self) -> None:
        """
        ### pyglet으로 외부 폰트를 추가해주는 함수
        """
        pyglet.font.add_file("../../Fonts/나눔손글씨 느릿느릿체.ttf")
        pyglet.font.add_file("../../Fonts/나눔손글씨 다시 시작해.ttf")
        pyglet.font.add_file("../../Fonts/나눔손글씨 북극성.ttf")
        pyglet.font.add_file("../../Fonts/나눔손글씨 암스테르담.ttf")
        pyglet.font.add_file("../../Fonts/나눔손글씨 옥비체.ttf")
        pyglet.font.add_file("../../Fonts/나눔손글씨 잘하고 있어.ttf")
        pyglet.font.add_file("../../Fonts/나눔손글씨 힘내라는 말보단.ttf")

    def menu_screen(self) -> None:
        """
        ### 메뉴 화면 구현 함수
        """
        menu_bg = self.maker.make_img(self.img_path("Bg/menu.png"), [0, 0])
        version_label = self.maker.make_label([1100, 10], ["Ver 2.0.0", "White", "Black", ("나눔손글씨 느릿느릿체", 20)])

        self.stage = 0
        self.cur_score = 0
        self.target_score = 0

        self.game_setting()

        play_btn = self.maker.make_btn_img(self.img_path("Btn/play.png"), [930, 250], self.stage_screen)
        rank_btn = self.maker.make_btn_img(self.img_path("Btn/rank.png"), [930, 350], self.rank_screen)
        how_btn = self.maker.make_btn_img(self.img_path("Btn/how.png"), [930, 450], self.how_screen)
        exit_btn = self.maker.make_btn_img(self.img_path("Btn/exit.png"), [930, 550], self.exit)

    def stage_screen(self) -> None:
        """
        스테이지 화면 구현 함수
        """
        stage_bg = self.maker.make_img(self.img_path("Bg/stage.png"), [0, 0])

        self.stage += 1
        self.target_score = 2*self.stage**2
        stage_label = self.maker.make_txt_img(self.img_path("Label/stage.png"), [450, 220], [f"STAGE {self.stage}", "White", ("나눔손글씨 옥비체", 55)])
        target_label = self.maker.make_txt_img(self.img_path("Label/score.png"), [493, 350], [f"목표점수 : {self.target_score}점", "White", ("나눔손글씨 옥비체", 30)])
        current_label = self.maker.make_txt_img(self.img_path("Label/score.png"), [493, 420], [f"현재점수 : {self.cur_score}점", "White", ("나눔손글씨 옥비체", 30)])

        stage_bg.after(3000, self.play_screen)

    def play_screen(self) -> None:
        """
        플레이 화면 구현 함수
        """
        game_bg = self.maker.make_img(self.img_path("Bg/game.png"), [0, 0])
        stage_label = self.maker.make_txt_img(self.img_path("Label/stage.png"), [860, 30], [f"STAGE {self.stage}", "White", ("나눔손글씨 옥비체", 55)])
        target_label = self.maker.make_txt_img(self.img_path("Label/score.png"), [945, 155], [f"목표점수 : {self.target_score}점", "White", ("나눔손글씨 옥비체", 30)])
        current_label = self.maker.make_txt_img(self.img_path("Label/score.png"), [945, 225], [f"현재점수 : {self.cur_score}점", "White", ("나눔손글씨 옥비체", 30)])
        cnt_card_pile = len(self.card_piles)
        if not cnt_card_pile:
            cnt_card_pile = 26
        self.cnt_card_label = self.maker.make_txt_img(self.img_path("Label/card_num.png"), [158, 306], [f"{cnt_card_pile}", "Black", ("나눔손글씨 옥비체", 30)])

        self.cnt_stage_card = 0
        self.stage_score = 0
        self.ace = 0

        self.go_btn = self.maker.make_btn_img(self.img_path("Btn/go.png"), [300, 70], self.open_card)
        stop_btn = self.maker.make_btn_img(self.img_path("Btn/stop.png"), [300, 170], self.get_point)

    
    def open_card(self) -> None:
        """
        카드 오픈 함수
        """
        if not self.card_piles:
            self.card_piles += self.new_card
            random.shuffle(self.card_piles)
        card = self.card_piles.pop()
        card_num = int(card[1:])
        self.stage_score += card_num
        if card_num==1:
            self.ace += 1
        card_img = self.maker.make_img(self.img_path(f"img/{card}.png"), [self.card_loc[self.cnt_stage_card], 350])
        cnt_card_pile = len(self.card_piles)
        if not cnt_card_pile:
            cnt_card_pile = 26
        self.cnt_card_label["text"] = cnt_card_pile
        self.cnt_stage_card += 1


        if self.cnt_stage_card==4:
            self.go_btn["state"] = "disabled"
    
    def get_point(self) -> None:
        """
        점수 획득 함수
        """
        if self.ace==1:
            if self.stage_score + 10 < 22:
                self.stage_score += 10
        elif self.ace==2:
            if self.stage_score + 20 < 22:
                self.stage_score += 20
            if self.stage_score + 10 < 22:
                self.stage_score += 10
            
        if self.stage_score > 21:
            self.cur_score += 0
            point_text = "카드 숫자의 합이\n21을 초과하므로\n0점을 획득합니다."
        elif self.stage_score == 21:
            self.cur_score += 21
            bonus = random.randint(25, 50)
            self.cur_score += bonus
            point_text = f"블랙잭! 21점과\n보너스 {bonus}점을 획득합니다."
        else:
            self.cur_score += self.stage_score
            point_text = f"{self.stage_score}점을 획득합니다."

        give_point_label = self.maker.make_txt_img(self.img_path("Label/givepoint.png"), [450, 30], [f"{point_text}", "Blue", ("나눔손글씨 힘내라는 말보단", 30)])


        if self.target_score > self.cur_score:
            give_point_label.after(3000, self.game_over)
        else:
            give_point_label.after(3000, self.stage_screen)

    def game_over(self) -> None:
        """
        게임 오버 화면 함수
        """
        game_over_bg = self.maker.make_img(self.img_path("Bg/gameover.png"), [0, 0])
        stage_label = self.maker.make_txt_img(self.img_path("Label/result.png"), [50, 370], [f"스테이지 {self.stage}", "White", ("나눔손글씨 힘내라는 말보단", 23)])
        target_label = self.maker.make_txt_img(self.img_path("Label/result.png"), [50, 450], [f"목표 점수 {self.target_score}", "White", ("나눔손글씨 힘내라는 말보단", 23)])
        cur_label = self.maker.make_txt_img(self.img_path("Label/result.png"), [200, 450], [f"현재 점수 {self.cur_score}", "White", ("나눔손글씨 힘내라는 말보단", 23)])
        self.name_entry = Entry(self.screen, fg="Blue", font=("나눔손글씨 힘내라는 말보단", 30), width=8, bd=8, relief="ridge")
        self.name_entry.insert(0, "JOKER")
        self.name_entry.place(x=50, y=580)
        register_btn = self.maker.make_btn_img(self.img_path("Btn/register.png"), [217, 583], self.save_rank)
        
    def save_rank(self) -> None:
        """
        랭킹 등록 함수
        """
        self.name_entry.config(state="disabled")
        nicname = self.name_entry.get()
        self.rank_db.save(nicname, self.stage, self.cur_score)
        self.menu_screen()

    def rank_screen(self) -> None:
        """
        ### 랭킹 화면 구현 함수
        """
        rank_bg = self.maker.make_img(self.img_path("Bg/rank.png"), [0, 0])
        back_btn = self.maker.make_btn_img(self.img_path("Btn/back.png"), [1025, 580], self.menu_screen)
        rank_data = self.rank_db.get_topten()
        rank_label_pos = [[610, 217], [610, 280], [610, 343], [610, 406], [610, 469], [920, 217], [920, 280], [920, 343], [920, 406], [920, 469]]
        for i in range(10):
            rank_label = self.maker.make_txt_img(self.img_path("Label/rank.png"), [rank_label_pos[i][0], rank_label_pos[i][1]], 
                                                 [f"{rank_data[i][0]} {rank_data[i][1]}점", "White", ("나눔손글씨 힘내라는 말보단", 25)])

    def how_screen(self) -> None:
        """
        ### 게임 방법 설명 화면 구현 함수
        """
        how_bg = self.maker.make_img(self.img_path("Bg/how.png"), [0, 0])
        back_btn = self.maker.make_btn_img(self.img_path("Btn/back.png"), [1025, 580], self.menu_screen)

    def no_action(self) -> None:
        """
        ### 아무일도 일어나지 않는 이벤트 함수
        """
        pass

    def exit(self):
        """
        ### 게임을 종료시키는 함수
        """
        answer = messagebox.askyesno("확인", "정말 종료하시겠습니까?")
        if answer:
            self.screen.destroy()
            self.screen.quit()
            exit()

if __name__=="__main__":
    execute = Game_Screen()