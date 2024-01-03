import os

from maker import maker
from tkinter import *
from typing import *


class Game_Screen:
    def __init__(self) -> None:
        """
        ### Black Jack 게임 실행 Class
        """
        self.screen = Tk()
        self.screen.title("Black Jack 2.0.0")
        self.set_screen_size()
        self.img_maker = maker(self.screen)
        self.python_path = os.path.join(os.getcwd())
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

    def menu_screen(self) -> None:
        """
        ### 메뉴 화면 구현 함수
        """
        menu_bg = self.img_maker.make_img(self.img_path("Bg/menu.png"), [0, 0])
        


if __name__=="__main__":
    execute = Game_Screen()