from tkinter import *





class Game_Screen:
    def __init__(self) -> None:
        self.screen = Tk()
        self.screen.title("Black Jack 2.0.0")
        self.set_screen_size()
        self.screen.mainloop()

    def set_screen_size(self) -> None:
        screen_width = 1200
        screen_height = 700
        windows_width = self.screen.winfo_screenwidth()
        windows_height = self.screen.winfo_screenheight()
        center_width = (windows_width - screen_width)//2
        center_height = (windows_height - screen_height)//2
        self.screen.geometry(f"{screen_width}x{screen_height}-{center_width}-{center_height}")
        self.screen.resizable(width=False, height=False)




if __name__ == "__main__":
    run = Game_Screen()