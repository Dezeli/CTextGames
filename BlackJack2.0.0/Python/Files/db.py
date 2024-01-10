import sqlite3
import datetime
from typing import *

class DataBase:
    def __init__(self) -> None:
        """
        ### Rank 저장 및 관리를 위한 Database Class
        """
        self.db = sqlite3.connect("../../Database/Rank.db")
        self.cursor = self.db.cursor()

    def save(self, name:str, stage:int, point:int) -> None:
        """
        ### Rank 테이블에 데이터를 insert하는 함수
        name : 닉네임
        stage : 스테이지
        point : 점수
        """
        cnt = self.get_cnt()
        date = datetime.datetime.now()
        date = f"{date.year}년 {date.month}월 {date.day}일"
        insert_query = f'INSERT INTO Rank VALUES("{cnt+1}", "{name}", "{stage}", "{point}", "{date}")'
        self.cursor.execute(insert_query)
        self.db.commit()


    def get_topten(self) -> List:
        """
        ### Rank 테이블의 점수 탑 10을 가져오는 함수
        """
        self.cursor.execute(f'SELECT Name, Point FROM Rank Order By "Point" DESC LIMIT 10')
        data = self.cursor.fetchall()
        return data



    def get_cnt(self) -> int:
        """
        ### Rank 테이블의 행 개수를 return하는 함수
        """
        self.cursor.execute("SELECT count(*) FROM Rank")
        cnt = self.cursor.fetchone()[0]
        return cnt
