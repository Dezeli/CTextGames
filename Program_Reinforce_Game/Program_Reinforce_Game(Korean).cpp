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
	int money = 1000;
	int probability = 0;
	int success = 0;
	int level = 0;
	int sellingprice = 0;
	int buyingprice = 0; 
	int choice = 0; 
	int random = rand()%100;
	int choose = 0;
	int buypick = 100; 
	int ranpro;
	int plus; 
	int lottomoney;
	int lottoper;
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

	
	gotoxy(32,2);
	printf("*���α׷� ��ȭ����*");
	Sleep(3000);
	gotoxy(10,5);
	printf("���α׷� ��ȭ������ �����մϴ�.");
	Sleep(2000);
	gotoxy(10,7);
	printf("�� �� ���� ���� �� �ֳ� �����غ�����!");
	gotoxy(10,9);
	Sleep(2000);
	printf("�⺻�� 1000���� �־����ϴ�.");
	Sleep(2000);
	gotoxy(10,12);
	printf(" �ؼ����� �ѱ�,������� ���ڷθ� �����ؾ� �մϴ�.��"); 
	gotoxy(10,15);
	printf(" �����α׷� ���Ž� ������ ���α׷��� ������ϴ�.��"); 
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
	
	
	while(money!=1000000000000000){
	
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
		gotoxy(0,4);
	printf("      ��                                                                  ��\n");
	gotoxy(0,10);
	printf("      ��                                                                  ��\n");
	gotoxy(0,11);
	printf("      ��                                                                  ��\n");
	gotoxy(0,13);
	printf("      ��                                                                  ��\n");
	gotoxy(0,14);
	printf("      ��                                                                  ��\n");
	gotoxy(0,15);
	printf("      ��                                                                  ��\n");
	Sleep(500);
	gotoxy(10,6);
	printf("���� �� : %d��      ���� ���α׷�: %d ��",money,level);
	gotoxy(10,9);
	printf("1. ��ȭ�ϱ�(%d%%)   2. ���α׷� ���   3.������ ����  4.�ζ�",probability);
	gotoxy(10,12);
	printf("������ �Ͻǰǰ��� (1,2,3���� �������ּ���)      ");
	scanf("%d", &choice);
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
		gotoxy(0,4);
	printf("      ��                                                                  ��\n");
	gotoxy(0,10);
	printf("      ��                                                                  ��\n");
	gotoxy(0,11);
	printf("      ��                                                                  ��\n");
	gotoxy(0,13);
	printf("      ��                                                                  ��\n");
	gotoxy(0,14);
	printf("      ��                                                                  ��\n");
	gotoxy(0,15);
	printf("      ��                                                                  ��\n");
	Sleep(500);
	
	if(choice==1 && level==0){
		gotoxy (10,7);
		printf("���α׷��� �����ϴ�. ���α׷��� ���� �������ּ���!");
		Sleep(3000);
	}
	else if(choice==4){
		gotoxy(10,7);
		printf("�󸶸� ����Ͻðڽ��ϱ�? (���ڷ� �Է�)    ");
		scanf("%d",&lottomoney);
		if(lottomoney<=money){
			
			srand((unsigned int) time(NULL));
			lottoper=rand()%9;
			srand((unsigned int) time(NULL));
			gotoxy(30,10); 
			printf("~~�� ��÷�Ǽ̽��ϴ�.");
			Sleep(3000);
			gotoxy(10,10);
			if(lottoper==6){
				money=money-lottomoney;
				printf("5��!!!!!");
				money=money+lottomoney*5;
				Sleep(3000);
			}
			else if(lottoper==9){
				money=money-lottomoney;
				printf("10��...");
				money=money+lottomoney*10;
				Sleep(3000);
			}
			else if(lottoper==8){
				money=money-lottomoney;
				printf("2��!");
				money=money+lottomoney*2;
				Sleep(3000);
			}
			else if(lottoper==7){
				money=money-lottomoney;
				printf("3��~~");
				money=money+lottomoney*3;
				Sleep(3000);
			}
			else{
				printf("0��..�Ф�");
				money=money-lottomoney;
				money=money+lottomoney*0;
				Sleep(3000);
			}
			}
		else{
			gotoxy(10,9);
			printf("���� �����մϴ�.");
			Sleep(2000); 
		}
	}
	else if(choice==2017){
	gotoxy(10,8);
	printf("ġƮ �ߵ�!  �� 30000�� �߰� !!");
	Sleep(2000);
	money=money+30000;
	}
	else if(choice==3){
		gotoxy(10,6);
			printf("0.������");
			gotoxy(10,7);
			printf("1. 2%% Ȯ�� ���̱�  ���(1000��)");
			gotoxy(10,8);
			printf("2. 5%% Ȯ�� ���̱�  ���(2000��)");
			gotoxy(10,9);
			printf("3. 10%% Ȯ�� ���̱� ���(3500��)");
			gotoxy(10,10);
			printf("4. ��ȭ ������ +3��(�ߺ� �Ұ�)(5000��)");
			gotoxy(10,11);
			printf("5. ��ȭ ������ +5��(�ߺ� �Ұ�)(10000��)");
			gotoxy(10,12); 
			printf("������ �����ұ��?    ");
			scanf("%d",&buypick);
			Sleep(500);
				gotoxy(0,6);
	printf("      ��                                                                  ��\n");
	gotoxy(0,7);
	printf("      ��                                                                  ��\n");
	gotoxy(0,8);
	printf("      ��                                                                  ��\n");
	gotoxy(0,9);
	printf("      ��                                                                  ��\n");
	gotoxy(0,10);
	printf("      ��                                                                  ��\n");
	gotoxy(0,11);
	printf("      ��                                                                  ��\n");
	gotoxy(0,12);
	printf("      ��                                                                  ��\n");
				if(buypick==1&&money>=1000){	
				gotoxy(10,9);
					printf("Ȯ�� + 2%%");
					Sleep(2000);
					money=money-1000;
					probability = probability+2;
				}
				else if(buypick==0){
				}
				else if(buypick==2&&money>=2000){
					gotoxy(10,9);
					printf("Ȯ�� + 5%%");
					Sleep(2000);
					money=money-2000;
					probability = probability+5;
				}
				else if(buypick==3&&money>=3500){
					gotoxy(10,9);
					printf("Ȯ�� + 10%%");
					Sleep(2000);
					money=money-3500;
					probability = probability + 10;
				}
					else if(buypick==4&&money>=5000){
					gotoxy(10,9);
					printf("��ȭ ������ +3��");
					Sleep(2000);
					money=money-5000;
					plus=1;
				}
				else if(buypick==5&&money>=10000){
					gotoxy(10,9);
					printf("��ȭ ������ +5��");
					Sleep(2000);
					money=money-10000;
					plus=2;
				}
				else{
					gotoxy(10,9);
					printf("�ٽ� ������ �ּ���\n\n");
						Sleep(2000);
				}
		}
	else if(choice==1 && level!=0){
		if(random<=probability){
			gotoxy(10,5);
			printf("��");
			Sleep(500);
			gotoxy(10,6);
			printf("ȭ");
			Sleep(500);
			gotoxy(10,7);
			printf("��");
			Sleep(500);
			gotoxy(10,8);
			printf("��ȭ��");
			Sleep(1000);
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
			srand((unsigned int) time(NULL));
			random = rand()%100;
			gotoxy(10,8);
			printf("��ȭ��");
			Sleep(500);
			gotoxy(50,8);
			printf("�ϼ̽��ϴ�");
			Sleep(1000);
			gotoxy(30,8);
			printf("����!!!");
			Sleep(3000);
			if(plus==1){
				level= level+3;
			probability = 100 - level;
	gotoxy(10,12);
	printf("��ȭ ����� 3�ܰ� �ö󰩴ϴ�");
	plus=0;
			} 
			else if(plus==2){
				level= level+5;
			probability = 100 - level;
	gotoxy(10,12);
	printf("��ȭ ����� 5�ܰ� �ö󰩴ϴ�");
			plus=0;
			} 
			else{
			level= level+1;
			probability = 100 - level;
	gotoxy(10,12);
	printf("��ȭ ����� 1�ܰ� �ö󰩴ϴ�");
	}
	Sleep(2000);
	sellingprice=level*10;
	money=money+sellingprice;
	gotoxy(10,14);
	printf("%d���� ȹ���ϼ̽��ϴ�.",sellingprice); 
	Sleep(2000);
		}
		else{
			gotoxy(10,5);
			printf("��");
			Sleep(500);
			gotoxy(10,6);
			printf("ȭ");
			Sleep(500);
			gotoxy(10,7);
			printf("��");
			Sleep(500);
			gotoxy(10,8);
			printf("��ȭ��");
			Sleep(1000);
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
			srand((unsigned int) time(NULL));
			random = rand()%100;
			gotoxy(10,8);
			printf("��ȭ��");
			Sleep(500);
			gotoxy(50,8);
			printf("�ϼ̽��ϴ�");
			Sleep(1000);
			gotoxy(30,8);
			printf("����....");
			Sleep(3000); 
			level= level-5; 
			probability = 100 - level;
	gotoxy(10,12);
	printf("��ȭ ����� 5�ܰ� �������ϴ�...");
		}
	}

	else if(choice==2){
			gotoxy(10,6);
			printf("0.������");
			gotoxy(10,7);
			printf("1. 1�� ���α׷� ���(100��)");
			gotoxy(10,8);
			printf("2. 10�����α׷� ���(300��)");
			gotoxy(10,9);
			printf("3. 20�� ���α׷� ���(1000��)");
			gotoxy(10,10);
			printf("4. 30�� ���α׷� ���(3000��)");
			gotoxy(10,11);
			printf("5. 30~60�� ���α׷� ���(10000��)");
			gotoxy(10,12); 
			printf("������ �����ұ��?    ");
			scanf("%d",&buypick);
			Sleep(500);
				gotoxy(0,6);
	printf("      ��                                                                  ��\n");
	gotoxy(0,7);
	printf("      ��                                                                  ��\n");
	gotoxy(0,8);
	printf("      ��                                                                  ��\n");
	gotoxy(0,9);
	printf("      ��                                                                  ��\n");
	gotoxy(0,10);
	printf("      ��                                                                  ��\n");
	gotoxy(0,11);
	printf("      ��                                                                  ��\n");
	gotoxy(0,12);
	printf("      ��                                                                  ��\n");
	if(buypick==1&&money>=100){	
				gotoxy(10,9);
					printf("1�� ���α׷��� �����Ͽ����ϴ�.");
					Sleep(2000);
					money=money-100;
					level=1;
					probability = 100 - level;
				}
				else if(buypick==0){
				}
				else if(buypick==2&&money>=300){
					gotoxy(10,9);
					printf("10�� ���α׷��� �����Ͽ����ϴ�.");
					Sleep(2000);
					money=money-300;
					level=10;
					probability = 100 - level;
				}
				else if(buypick==4&&money>=3000){
					gotoxy(10,9);
					printf("30�� ���α׷��� �����Ͽ����ϴ�.");
					Sleep(2000);
					money=money-3000;
					level=30;
					probability = 100 - level;
					}
					else if(buypick==5&&money>=10000){
					gotoxy(10,9);
					srand((unsigned int) time(NULL));
					ranpro=rand()%30+30;
					printf("%d�� ���α׷��� �����Ͽ����ϴ�.",ranpro);
					Sleep(2000);
					money=money-10000;
					level=ranpro;
					probability = 100 - level;
				}
				else if(buypick==3&&money>=1000){
					gotoxy(10,9);
					printf("20�� ���α׷��� �����Ͽ����ϴ�.");
					Sleep(2000);
					money=money-1000;
					level=20;
					probability = 100 - level;
				}
				else{
					gotoxy(10,9);
					printf("�ٽ� ������ �ּ���\n\n");
						Sleep(2000);
				}
		}
	else{
		gotoxy (10,7);
		printf("�ٽ� ������ �ּ���! ���� �� �� �����ϴ�!");
		Sleep(3000);
	}		
		
}
printf("�¸��ϼ̽��ϴ�."); 
return 0;
}
