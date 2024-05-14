#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void print_year(int year);//输出年历的函数，调用了days，which_week函数
void print_week();//输出星期几的一个简单函数
void print_month(int year,int month);//输出某月的月历，调用了days，which_week函数
int which_week(int year,int month);//计算该月1号是星期几
int days(int year,int month);//记录某月有多少天
void long_day(int year,int month,int day);
int main()
{
	printf("课程设计：万年历(5级)\n");
	printf("(1) 输入'1'查询指定年年历;\n");
	printf("(2) 输入'2'查询指定年月的日历;\n");
	printf("(3) 输入'3'查询指定日期距今的天数;\n");
	printf("请输入操作指令(1、2或3):\n");
	int year,month,day;
	int c;
	scanf("%d",&c);
	if(c==1)
	{
		printf("----------------------------\n");
		printf("请输入年份：\n");
		scanf("%d",&year);
		if(year>=10000||year<=0)
		{
			printf("年份超出万年范围！\n");
			exit(0);
		}
		else
			print_year(year);
	}
	else if(c==2)
	{
		printf("----------------------------\n");
		printf("请输入年份和月份：\n");
		scanf("%d%d",&year,&month);
		if(year>9999||year<1)
		{
			printf("年份超出万年范围！\n");
			exit(0);
		}
		if(month>12||month<1)
		{
			printf("月份超出1~12范围！\n");
			exit(0);
		}
		print_month(year,month);
		printf("\n");
	}
	else if(c==3)
	{
		printf("----------------------------\n");
		printf("请输入年、月、日：\n");
		scanf("%d%d%d",&year,&month,&day);
		if(year>9999||year<1)
		{
			printf("年份超出万年范围！\n");
			exit(0);
		}
		if(month>12||month<1)
		{
			printf("月份超出1~12范围！\n");
			exit(0);
		}
		if(day>days(year,month)||day<1)
		{
			printf("日期超出范围！\n");
			exit(0);
		}
		long_day(year,month,day);
	}
	else
		printf("指令错误！\n");
}

void print_week()
{
	printf("日 一 二 三 四 五 六");
}

int days(int year,int month)//该函数会返回该月的天数
{
	int date;//用于记录该月的天数	
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
	int p;//用于判断该年是不是闰年
	if((year%4==0&&year%100!=0)||year%400==0)
		p=1;
	else
		p=0;
	int a;//用于记录该月1号是该年第几天
	int date=days(year,month);//用于记录该月的天数	
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
	int s=((year-1)+((year-1)/4)-((year-1)/100)+((year-1)/400)+a)%7;//计算该月1号是星期几
	return s;
}


void long_day(int year,int month,int day)
{
	int p;//用于判断该年是不是闰年
	if((year%4==0&&year%100!=0)||year%400==0)
		p=1;
	else
		p=0;
	int ts1,ts2;//储存输入总天数和现在的总天数
	int a;//储存该年已过天数
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
		printf("该时间距今还有%d天\n",ts1-ts2);
	else
		printf("该时间距今已过%d天\n",ts2-ts1);
	switch((which_week(year,month)+day-1)%7)//判断为星期几
	{
		case 0:printf("该天是星期日\n");break;
		case 1:printf("该天是星期一\n");break;
		case 2:printf("该天是星期二\n");break;
		case 3:printf("该天是星期三\n");break;
		case 4:printf("该天是星期四\n");break;
		case 5:printf("该天是星期五\n");break;
		case 6:printf("该天是星期六\n");break;
	}

	switch(month)//判断是否为公历节日
	{
		case 1:
			if(day==1)printf("该天是元旦节！\n");
			else printf("该天不是公历节日！\n");break;
		case 2:
			printf("该天不是公历节日！\n");break;
		case 3:
			if(day==8)printf("该天是妇女节！\n");
			if(day==12)printf("该天是植树节！\n");
			else printf("该天不是公历节日！\n");break;
		case 4:
			printf("该天不是公历节日！\n");break;
		case 5:
			if(day==1)printf("该天是劳动节！\n");
			if(day==4)printf("该天是青年节！\n");
			else printf("该天不是公历节日！\n");break;
		case 6:
			if(day==1)printf("该天是儿童节！\n");
			else printf("该天不是公历节日！\n");break;
		case 7:
			if(day==1)printf("该天是建党节！\n");
			else printf("该天不是公历节日！\n");break;
		case 8:
			if(day==1)printf("该天是建军节！\n");
			else printf("该天不是公历节日！\n");break;
		case 9:
			if(day==10)printf("该天是教师节！\n");
			else printf("该天不是公历节日！\n");break;
		case 10:
			if(day==1)printf("该天是国庆节！\n");
			else printf("该天不是公历节日！\n");break;
		default:
			printf("该天不是公历节日！\n");break;
	}

}

void print_month(int year,int month)
{
	int i;//用于循环
	int b=1;//用于日期的循环
	int s=which_week(year,month)+1;
	int date=days(year,month);
	print_week();
	printf("\n");
	for(i=1;i<s;i++)
		printf("   ");
	for(i=0;i<date;i++)
	{
		printf("%2d ",b);
		b++;
		if(s==7)
		{
			printf("\n");
			s=0;
		}
		s++;	
	}
}



void print_year(int year)//输出年历 3行4列
{
	int z;
	int b1,b2,b3,b4;//用于记录天数
	int i,j,k;
	int a,b,c,d;//用于记录每个月的天数
	int m=1,n=1;//用于记录月份
	for(i=1;i<=3;i++)
	{
		int e,f,g,h;//表示天数
	    e=f=g=h=1;
		z=1;
		while(1)
		{
			printf("%d年%d月             ",year,m);
			if(m%4==0)
				break;
			m++;
		}
		m++;
		printf("\n");
		for(j=1;j<=4;j++)
			printf("--------------------  ");
		printf("\n");
		for(j=1;j<=4;j++)
		{
			print_week();
			printf("  ");
		}
		printf("\n");

		for(k=0;k<6;k++)//输出日期
		{
			if(z==1)//第一，五，九月
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

			if(z==1)//第二，六，十月
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
				c=which_week(year,n)+1;//第三，七，十一月
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
				d=which_week(year,n)+1;//第四，八，十二月
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

