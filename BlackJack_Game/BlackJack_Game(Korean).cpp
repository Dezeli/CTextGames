#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <windows.h> 




void gotoxy(int x, int y)
{
 COORD CursorPosition = { x, y };
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}



int main(void){
	int i; //�� �� 
	int helpsco=0;
	int level = 1;   //���� 
	int levelscore=0;    //��ǥ ���� 
	int card=0;       //���� ī�� 
	int cardplus=0;  //�������� 
	int scoreplus=0;  //���� 
	int plascore=0;  //�÷��̾� �� ���� 
	int choice=0;  //�÷��̾� ���� 1�Ǵ� 2
	int bonusscore=0; //21 ���ʽ� ���� 
	 
	srand((unsigned int) time(NULL));

	printf("      �ʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢ�\n");
	printf("      ��                                                                  ��\n");
	printf("      ��                                                                  ��\n");
	printf("      ��                                                                  ��\n");
	printf("      ��                                                                  ��\n");
	printf("      ��                                                                  ��\n");
	printf("      ��                                                                  ��\n");
	printf("      ��                                                                  ��\n");
	printf("      ��                                                                  ��\n");
	printf("      ��                                                                  ��\n");
	printf("      ��                                                                  ��\n");
	printf("      ��                                                                  ��\n");
	printf("      ��                                                                  ��\n");
	printf("      ��                                                                  ��\n"); 
	printf("      ��                                                                  ��\n");
	printf("      ��                                                                  ��\n");
	printf("      ��                                                                  ��\n");
	printf("      ��                                                                  ��\n");
	printf("      ��                                                                  ��\n");
	printf("      ��                                                                  ��\n");
	printf("      �ʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢʢ�\n");

	
	gotoxy(28,2);
	printf("*�����̹� ���� ����*");
	Sleep(3000);
	gotoxy(10,5);
	printf("�����̹� ���� ������ �����մϴ�.");
	Sleep(2000);
	gotoxy(10,7);
	printf("�󸶳� ��ƿ �� �ִ��� �����غ�����!");
	gotoxy(10,9);
	Sleep(2000);
	printf("1�� ī��̱�, 2�� �׸� �̱��Դϴ�.");
	Sleep(2000);
	gotoxy(10,12);
	printf("���ڷθ� �����ּ���! �������ϴ�."); 
	Sleep (5000);
	gotoxy(0,5);
	printf("      ��                                                                  ��\n");
	gotoxy(0,6);
	printf("      ��                                                                  ��\n");
	gotoxy(0,7);
	printf("      ��                                                                  ��\n");
	gotoxy(0,8);
	printf("      ��                                                                  ��\n");
	gotoxy(0,9);
	printf("      ��                                                                  ��\n");
	gotoxy(0,12);
	printf("      ��                                                                  ��\n");
	gotoxy(0,15);
	printf("      ��                                                                  ��\n");
	Sleep(500);
	
	gotoxy(10,5);
	printf("���� �� ����.");
	Sleep(2000);
	gotoxy(10,7);
	printf("���帶�� ��ǥ ������ �ֽ��ϴ�.");
	gotoxy(10,9);
	Sleep(2000);
	printf("���� ������ ���� ���� ��ǥ������ �Ѿ�� ����Դϴ�.");
	gotoxy(10,12);
	Sleep(2000);
	printf("������ ��� ���� 25~50������ ������ �������� �޽��ϴ�.");
	Sleep(2000);
	gotoxy(10,15);
	printf("���� ���ڰ� 21�� ���� �� bust, 0���̴� ������ �����ϼ���.");
	Sleep (5000);
	gotoxy(0,5);
	printf("      ��                                                                  ��\n");
	gotoxy(0,6);
	printf("      ��                                                                  ��\n");
	gotoxy(0,7);
	printf("      ��                                                                  ��\n");
	gotoxy(0,8);
	printf("      ��                                                                  ��\n");
	gotoxy(0,9);
	printf("      ��                                                                  ��\n");
	gotoxy(0,12);
	printf("      ��                                                                  ��\n");
	gotoxy(0,15);
	printf("      ��                                                                  ��\n");
	Sleep(500);
	
	
	while(plascore>=levelscore){
	Sleep(500);
	helpsco=helpsco+2;
	levelscore=level*helpsco;
	gotoxy(10,5);
	printf("%d���� ��ǥ ������ %d���Դϴ�.",level,levelscore);
	Sleep(2000);
	gotoxy(10,7);
	printf("ī�带 �������� �̰ڽ��ϴ�.(1~11)");
	Sleep(3000);
	for(i=1;i<=5;i++){
	srand((unsigned int) time(NULL));
	card=rand()%10+1;
	gotoxy(10,9+i);
	printf("%d            ",card);
	Sleep(500);
	cardplus=cardplus+card; 
	printf("1(go),2(stop)   ");
	scanf("%d",&choice);
	Sleep(500);
	if(choice==1){
	if(cardplus>21){
			gotoxy(10,16);
			printf("bust�̹Ƿ� 0���Դϴ�.");
			Sleep(2000);
			cardplus=0;
			break;
	}
	else if(cardplus==21){
			srand((unsigned int) time(NULL));
			bonusscore=rand()%25+25;
			gotoxy(10,16);
			printf("�����̹Ƿ� %d(25~50)���� ȹ���մϴ�.",bonusscore);
			plascore=plascore+bonusscore;
			Sleep(2000);
			break;
}
}
	else if(choice==2){
		if(cardplus>21){
			gotoxy(10,16);
			printf("bust�̹Ƿ� 0���Դϴ�.");
			Sleep(2000);
			cardplus=0;
			break;
		} 
		else if(cardplus==21){
			srand((unsigned int) time(NULL));
			bonusscore=rand()%25+25;
			gotoxy(10,16);
			printf("�����̹Ƿ� %d(25~50)���� ȹ���մϴ�.",bonusscore);
			plascore=plascore+bonusscore;
			Sleep(2000);
			break;	
		}
		else{
			break;
		}
	}
	else{
		gotoxy(10,16);
		printf("����� �Է¹��� ���� stop�մϴ�.");
		Sleep(2000);
		gotoxy(0,16);
		printf("      ��                                                                  ��\n");
		break;
	}	
	
}
	gotoxy(10,17);
	printf("%d���� ȹ���ϼ̽��ϴ�.",cardplus);
	Sleep(4000);
	plascore=plascore+cardplus;
	level=level+1;
	cardplus=0;
	gotoxy(0,5);
	printf("      ��                                                                  ��\n");
	gotoxy(0,7);
	printf("      ��                                                                  ��\n");
	gotoxy(0,10);
	printf("      ��                                                                  ��\n");
	gotoxy(0,11);
	printf("      ��                                                                  ��\n");
	gotoxy(0,12);
	printf("      ��                                                                  ��\n");
	gotoxy(0,13);
	printf("      ��                                                                  ��\n");
	gotoxy(0,14);
	printf("      ��                                                                  ��\n");
	gotoxy(0,16);
	printf("      ��                                                                  ��\n");
	gotoxy(0,17);
	printf("      ��                                                                  ��\n");
	Sleep(1000);
	gotoxy(30,9);
	printf("%d ����",level);
	gotoxy(30,11);
	printf("�÷��̾� ���� : %d��",plascore);
	Sleep(5000);
	gotoxy(0,9);
	printf("      ��                                                                  ��\n");
	gotoxy(0,11);
	printf("      ��                                                                  ��\n");
	
}
		gotoxy(10,8);
		printf("��ǥ������ ���� ���� ������ �����ϴ�.");
		gotoxy(10,10);
		printf("����� ������ %d��, %d���忡�� Ż���ϼ̽��ϴ�.",plascore,level-1);
		
	
	Sleep(10000000);


}

