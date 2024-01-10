import os
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

        play_btn = self.maker.make_btn_img(self.img_path("Btn/play.png"), [930, 250], self.no_action)
        rank_btn = self.maker.make_btn_img(self.img_path("Btn/rank.png"), [930, 350], self.rank_screen)
        how_btn = self.maker.make_btn_img(self.img_path("Btn/how.png"), [930, 450], self.how_screen)
        exit_btn = self.maker.make_btn_img(self.img_path("Btn/exit.png"), [930, 550], self.exit)

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
                                                 [f"{rank_data[i][0]} {rank_data[i][1]}", "White", ("나눔손글씨 힘내라는 말보단", 25)])

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