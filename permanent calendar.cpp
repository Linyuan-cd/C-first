#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print_year(int year);//��������ĺ�����������days��which_week����

void print_week();//������ڼ���һ���򵥺���

void print_month(int year, int month);//���ĳ�µ�������������days��which_week����

int which_week(int year, int month);//�������1�������ڼ�

int days(int year, int month);//��¼ĳ���ж�����

void long_day(int year, int month,int day);

void nume();

int main()
{
	nume();
	int year,month,day;
	int op;
	printf("\t������ָ��:\n\t>>");
	scanf("%d", &op);
	while(op < 1 || op > 5)
	{
		printf("\tָ�����!����������\n\t>>");
		scanf("%d", &op);
	}

	while(op != 5)
	{
		switch (op)
		{
		case 1:
			{
				printf("----------------------------\n");
				printf("\t\t���������:\n\t\t>>");
				scanf("%d",&year);
				while(year>=10000||year<=0)
				{
					printf("\t\t��ݳ������귶Χ!����������\n\t\t>>");
					scanf("%d",&year);
				}
				print_year(year);
			}break;
		case 2:
			{
				printf("----------------------------\n");

				printf("\t\t���������:\n\t\t>>");
				scanf("%d", &year, &month);
				while(year>=10000||year<=0)
				{
					printf("\t\t��ݳ������귶Χ!����������\n\t\t>>");
					scanf("%d",&year);
				}

				printf("\t\t�������·�:\n\t\t>>");
				scanf("%d", &month);
				while(month>12||month<1)
				{
					printf("\t\t�·ݳ���1~12��Χ!����������\n\t\t>>");
					scanf("%d",&month);
				}
				
				print_month(year, month);
				printf("\n");
			}break;
		case 3:
			{
				printf("----------------------------\n");

				printf("\t\t���������:\n\t\t>>");
				scanf("%d", &year);
				while(year>=10000||year<=0)
				{
					printf("\t\t��ݳ������귶Χ!����������\n\t\t>>");
					scanf("%d",&year);
				}

				printf("\t\t�������·�:\n\t\t>>");
				scanf("%d", &month);
				while(month>12||month<1)
				{
					printf("\t\t�·ݳ���1~12��Χ!����������\n\t\t>>");
					scanf("%d",&month);
				}

				printf("\t\t����������:\n\t\t>>");
				scanf("%d", &day);
				while(day>days(year,month)||day<1)
				{
					printf("\t\t���ڳ�����Χ!����������\n\t\t>>");
					scanf("%d",&day);
				}

				long_day(year,month,day);
			}break;
		case 4:
			{
				system("cls");
				nume();
			}
		}
		printf("\t������ָ��:\n\t>>");
		scanf("%d", &op);
		while(op < 1 || op > 5)
		{
			printf("\tָ�����!����������\n\t>>");
			scanf("%d", &op);
		}
	}
    return 0;
}


void print_week()
{
	printf("�� һ �� �� �� �� ��");
}

int days(int year,int month)//�ú����᷵�ظ��µ�����
{
	int date;//���ڼ�¼���µ�����	
	switch(month)
	{
	    case 1:date=31;break;
		case 2:
			if((year%4==0&&year%100!=0)||year%400==0)
				date=29;
			else
				date=28;break;
		case 3:date=31;break;
		case 4:date=30;break;
		case 5:date=31;break;
		case 6:date=30;break;
		case 7:date=31;break;
		case 8:date=31;break;
		case 9:date=30;break;
		case 10:date=31;break;
		case 11:date=30;break;
		case 12:date=31;break;
	}
	return date;
}



int which_week(int year,int month)
{
	int p;//�����жϸ����ǲ�������
	if((year%4==0&&year%100!=0)||year%400==0)
		p=1;
	else
		p=0;
	int a;//���ڼ�¼����1���Ǹ���ڼ���
	int date=days(year,month);//���ڼ�¼���µ�����	
	switch(month)
	{
	    case 1:a=1;break;
		case 2:a=32;break;
		case 3:(p==1)? a=61:a=60;break;
		case 4:(p==1)? a=92:a=91;break;
		case 5:(p==1)? a=122:a=121;break;
		case 6:(p==1)? a=153:a=152;break;
		case 7:(p==1)? a=183:a=182;break;
		case 8:(p==1)? a=214:a=213;break;
		case 9:(p==1)? a=245:a=244;break;
		case 10:(p==1)? a=275:a=274;break;
		case 11:(p==1)? a=306:a=305;break;
		case 12:(p==1)? a=336:a=335;break;
	}
	int s=((year-1)+((year-1)/4)-((year-1)/100)+((year-1)/400)+a)%7;//�������1�������ڼ�
	return s;
}


void long_day(int year,int month,int day)
{
	int p;//�����жϸ����ǲ�������
	if((year%4==0&&year%100!=0)||year%400==0)
		p=1;
	else
		p=0;
	int ts1,ts2;//�������������������ڵ�������
	int a;//��������ѹ�����
	ts1=365*(year-1)+(year-1)/4-(year-1)/100+(year-1)/400;
	switch(month)
	{
	    case 1:a=1;break;
		case 2:a=32;break;
		case 3:(p==1)? a=61:a=60;break;
		case 4:(p==1)? a=92:a=91;break;
		case 5:(p==1)? a=122:a=121;break;
		case 6:(p==1)? a=153:a=152;break;
		case 7:(p==1)? a=183:a=182;break;
		case 8:(p==1)? a=214:a=213;break;
		case 9:(p==1)? a=245:a=244;break;
		case 10:(p==1)? a=275:a=274;break;
		case 11:(p==1)? a=306:a=305;break;
		case 12:(p==1)? a=336:a=335;break;
	}
	ts1+=a;
	ts1+=day;
	time_t q=time(NULL);
	struct tm *sj=localtime(&q);
	ts2=365*(sj->tm_year+1900-1)+(sj->tm_year+1900-1)/4-(sj->tm_year+1900-1)/100+(sj->tm_year+1900-1)/400+sj->tm_yday+2;
	if(ts1>=ts2)
		printf("\t\t��ʱ������%d��\n",ts1-ts2);
	else
		printf("\t\t��ʱ�����ѹ�%d��\n",ts2-ts1);
	switch((which_week(year,month)+day-1)%7)//�ж�Ϊ���ڼ�
	{
		case 0:printf("\t\t������������\n");break;
		case 1:printf("\t\t����������һ\n");break;
		case 2:printf("\t\t���������ڶ�\n");break;
		case 3:printf("\t\t������������\n");break;
		case 4:printf("\t\t������������\n");break;
		case 5:printf("\t\t������������\n");break;
		case 6:printf("\t\t������������\n");break;
	}

	switch(month)//�ж��Ƿ�Ϊ��������
	{
		case 1:
			if(day==1)printf("\t\t������Ԫ����!\n");
			else printf("\t\t���첻�ǹ�������!\n");break;
		case 2:
			printf("\t\t���첻�ǹ�������!\n");break;
		case 3:
			if(day==8)printf("\t\t�����Ǹ�Ů��!\n");
			if(day==12)printf("\t\t������ֲ����!\n");
			else printf("\t\t���첻�ǹ�������!\n");break;
		case 4:
			printf("\t\t���첻�ǹ�������!\n");break;
		case 5:
			if(day==1)printf("\t\t�������Ͷ���!\n");
			if(day==4)printf("\t\t�����������!\n");
			else printf("\t\t���첻�ǹ�������!\n");break;
		case 6:
			if(day==1)printf("\t\t�����Ƕ�ͯ��!\n");
			else printf("\t\t���첻�ǹ�������!\n");break;
		case 7:
			if(day==1)printf("\t\t�����ǽ�����!\n");
			else printf("\t\t���첻�ǹ�������!\n");break;
		case 8:
			if(day==1)printf("\t\t�����ǽ�����!\n");
			else printf("\t\t���첻�ǹ�������!\n");break;
		case 9:
			if(day==10)printf("\t\t�����ǽ�ʦ��!\n");
			else printf("\t\t���첻�ǹ�������!\n");break;
		case 10:
			if(day==1)printf("\t\t�����ǹ����!\n");
			else printf("\t\t���첻�ǹ�������!\n");break;
		default:
			printf("\t\t���첻�ǹ�������!\n");break;
	}

}

void print_month(int year,int month)
{
	printf("\t\t");
	printf("--------------------  \n");
	int i,j=0;//����ѭ��
	int b=1;//�������ڵ�ѭ��
	int s=which_week(year,month)+1;
	int date=days(year,month);
	printf("\t\t");
	print_week();
	printf("\n");
	printf("\t\t");
	for(i=1;i<s;i++)
		printf("   ");
	for(i=0;i<date;i++)
	{
		if(s==1&&j)
		printf("\t\t");
		printf("%2d ",b);
		b++;
		if(s==7)
		{
			printf("\n");
			s=0;
		}
        j++;
		s++;	
	}
}



void print_year(int year)//������� 3��4��
{
	int z;
	int b1,b2,b3,b4;//���ڼ�¼����
	int i,j,k;
	int a,b,c,d;//���ڼ�¼ÿ���µ�����
	int m=1,n=1;//���ڼ�¼�·�
	for(i=1;i<=3;i++)
	{
		printf("\t\t");
		int e,f,g,h;//��ʾ����
	    e=f=g=h=1;
		z=1;
		while(1)
		{
			printf("%d��%d��             ",year,m);
			if(m%4==0)
				break;
			m++;
		}
		m++;
		printf("\n");
		printf("\t\t");
		for(j=1;j<=4;j++)
			printf("--------------------  ");
		printf("\n");
		printf("\t\t");
		for(j=1;j<=4;j++)
		{
			print_week();
			printf("  ");
		}
		printf("\n");

		for(k=0;k<6;k++)//�������
		{
			printf("\t\t");
			if(z==1)//��һ���壬����
			{
				a=which_week(year,n)+1;
				b1=days(year,n);
				n++;
				for(j=1;j<a;j++)
					printf("   ");	
			}
			while(1)
			{
				if(e>b1)
					printf("   ");
				else
				{
					printf("%2d ",e);
					e++;
				}
				if(a==7)
				{
					a=1;
					break;
				}
				a++;
			}
			printf(" ");

			if(z==1)//�ڶ�������ʮ��
			{
				b=which_week(year,n)+1;
				b2=days(year,n);
				n++;
				for(j=1;j<b;j++)
					printf("   ");
			}
			while(1)
			{
				if(f>b2)
					printf("   ");
				else
				{
					printf("%2d ",f);
					f++;
				}
				if(b==7)
				{
					b=1;
					break;
				}
				b++;	
			}
			printf(" ");

			if(z==1)
			{
				c=which_week(year,n)+1;//�������ߣ�ʮһ��
				b3=days(year,n);
				n++;
				for(j=1;j<c;j++)
					printf("   ");
			}
			while(1)
			{
				if(g>b3)
					printf("   ");
				else
				{
					printf("%2d ",g);
					g++;
				}
				if(c==7)
				{
					c=1;
					break;
				}
				c++;		
			}
			printf(" ");

			if(z==1)
			{
				d=which_week(year,n)+1;//���ģ��ˣ�ʮ����
				b4=days(year,n);
				n++;
				for(j=1;j<d;j++)
					printf("   ");
			}
			while(1)
			{
				if(h>b4)
					printf("   ");
				else
				{
					printf("%2d ",h);
					h++;
				}
				if(d==7)
				{
					d=1;
					break;
				}
				d++;
			}
			z=0;
			printf("\n");

		}
		printf("\n");
	}
}

void nume()
{
	printf("\t\t---------------------------NUME-----------------------\n");
	printf("\t\t1.��ѯָ��������                   \n");
	printf("\t\t2.��ѯָ�����µ�����                 \n");
	printf("\t\t3.��ѯָ�����ھ�������               \n");
	printf("\t\t4.ˢ����Ļ                      \n");
	printf("\t\t5.��������                      \n");
	printf("\t\t------------------------------------------------------\n");
}
