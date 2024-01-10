import os
from tkinter import *
from typing import *
from PIL import ImageTk

class maker:
    def __init__(self, screen:Tk):
        """
        ### Label과 Button을 쉽게 생성할 수 있도록 만들어주는 Class
        screen : Label과 Button을 생성할 Tkinter Screen
        """
        self.screen = screen
        self.dir_path = os.path.join(os.getcwd(), "images")

    def make_label(self, pos:List[int], txt:List) -> Label:
        """
        ### Label을 생성하는 함수
        pos : [x좌표, y좌표]
        txt : [내용, 글자 색, 배경 색, (폰트, 폰트 크기)]
        """
        label = Label(
            self.screen,
            text = txt[0],
            fg = txt[1],
            bg = txt[2],
            font = txt[3],
            height=1,
        )
        label.place(x=pos[0], y=pos[1])
        return label

    def make_img(self, file_name:str, pos:List[int]) -> Label:
        """
        ### Image Label을 생성하는 함수
        file_name : 사진 파일 경로
        pos : [x좌표, y좌표]
        """
        final_path = os.path.join(self.dir_path, file_name)
        img = ImageTk.PhotoImage(file=final_path)
        img_label = Label(self.screen)
        img_label.configure(image=img)
        img_label.image = img
        img_label.place(x=pos[0], y=pos[1])
        return img_label

    def make_txt_img(self, file_name:str, pos:List[int], txt:List) -> Label:
        """
        ### Image Text Label을 생성하는 함수
        file_name : 사진 파일 경로
        pos : [x좌표, y좌표]
        txt : [내용, 글자 색, (폰트, 폰트 크기)]
        """
        final_path = os.path.join(self.dir_path, file_name)
        img = ImageTk.PhotoImage(file=final_path)
        img_label = Label(self.screen, text=txt[0], fg=txt[1], font=txt[2], compound=CENTER)
        img_label.configure(image=img)
        img_label.image = img
        img_label.place(x=pos[0], y=pos[1])
        return img_label

    def make_btn_img(self, file_name:str, pos:List[int], cmd:Callable) -> Button:
        """
        ### Image Button을 생성하는 함수
        file_name : 사진 파일 경로
        pos : [x좌표, y좌표]
        cmd : 이벤트 함수
        """
        final_path = os.path.join(self.dir_path, file_name)
        img = ImageTk.PhotoImage(file=final_path)
        img_btn = Button(self.screen, command=cmd, overrelief=SOLID)
        img_btn.configure(image=img)
        img_btn.image = img
        img_btn.place(x=pos[0], y=pos[1])
        return img_btn

    def make_txt_btn_img(self, file_name:str, pos:List[int], cmd:Callable, txt:List) -> Button:
        """
        ### Image Text Label을 생성하는 함수
        file_name : 사진 파일 경로
        pos : [x좌표, y좌표]
        cmd : 이벤트 함수
        txt : [내용, 글자 색, (폰트, 폰트 크기)]
        """
        final_path = os.path.join(self.dir_path, file_name)
        img = ImageTk.PhotoImage(file=final_path)
        img_btn = Button(self.screen, command=cmd, overrelief=SOLID, text=txt[0], fg=txt[1], font=txt[2], compound=CENTER, justify=LEFT)
        img_btn.configure(image=img)
        img_btn.image = img
        img_btn.place(x=pos[0], y=pos[1])
        return img_btn