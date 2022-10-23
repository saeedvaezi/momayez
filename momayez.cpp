#include "Momayez.h"
#include <cmath>

long long int Momayez::made131(long long int mablagh, long long int moafiat
	, int mabna, int nahveh, int asnaf, int takhfif)
{
	if (0 == nahveh)//قانون قدیم
	{
		if (0 == mabna)//مبنای درآمد
		{
			if (0 == asnaf)//بدون حق اصناف
			{
				return maliat131old(mablagh - moafiat);

			}
			else if (1 == asnaf)//با حق اصناف
			{
				long long int asnafprice = 0, maliat = 0;
				asnafprice = asnaf131(mablagh - moafiat);
				maliat = maliat131old(mablagh - moafiat - asnafprice);
				return maliat + asnafprice;
			}
		}

		else if (1 == mabna)//مبنای مالیات
		{
			if (0 == asnaf)//بدون حق اصناف
			{
				long long int daramad = 0;
				daramad = daramad131old(mablagh);
				return daramad + moafiat;
			}
			else if (1 == asnaf)//با حق اصناف
			{
				long long int daramad = 0;
				daramad = daramad131oldAsnaf(mablagh);
				return daramad + moafiat;

			}
		}
	}

	else if (1 == nahveh)//قانون جدید
	{
		if (0 == mabna)//مبنای درآمد
		{
			if (0 == asnaf)//بدون حق اصناف
			{
				return maliat131new(mablagh - moafiat , takhfif);
			}
			else if (1 == asnaf)//با حق اصناف
			{
				long long int asnafprice = 0, maliat = 0;
				asnafprice = asnaf131(mablagh - moafiat);
				maliat = maliat131new(mablagh - moafiat - asnafprice , takhfif);
				return maliat + asnafprice;
			}
		}
		else if (1 == mabna)//مبنای مالیات
		{
			if (0 == asnaf)//بدون حق اصناف
			{
				long long int daramad = 0;
				daramad = daramad131new(mablagh , takhfif);
				return daramad + moafiat;
			}
			else if (1 == asnaf)//با حق اصناف
			{
				long long int daramad = 0;
				daramad = daramad131newAsnaf(mablagh , takhfif);
				return daramad + moafiat;
			}
		}
	}
	
	else if (2 == nahveh)//قانون 1401
	{
		if (0 == mabna)//مبنای درآمد
		{
			if (0 == asnaf)//بدون حق اصناف
			{
				return maliat1311401(mablagh - moafiat , takhfif);
			}
			else if (1 == asnaf)//با حق اصناف
			{
				long long int asnafprice = 0, maliat = 0;
				asnafprice = asnaf131(mablagh - moafiat);
				maliat = maliat1311401(mablagh - moafiat - asnafprice , takhfif);
				return maliat + asnafprice;
			}
		}
		else if (1 == mabna)//مبنای مالیات
		{
			if (0 == asnaf)//بدون حق اصناف
			{
				long long int daramad = 0;
				daramad = daramad1311401(mablagh , takhfif);
				return daramad + moafiat;
			}
			else if (1 == asnaf)//با حق اصناف
			{
				long long int daramad = 0;
				daramad = daramad1311401Asnaf(mablagh , takhfif);
				return daramad + moafiat;
			}
		}
	}
}
//*********************************************************************
//محاسبه حق اصناف
long long int Momayez::asnaf131(long long int daramad)
{
	return round(daramad*0.001);
}
//*********************************************************************
//محاسبه درآمد قدیم
long long int Momayez::daramad131old(long long int maliat)
{//تکمیل
	long long maliatlevel1= 4500000;
	long long maliatlevel2= 18500000;
	long long maliatlevel3= 56000000;
	long long maliatlevel4= 281000000;

	long long int daramad;
	if (maliat <= maliatlevel1)
		daramad = round(maliat/0.15);
	else if (maliat > maliatlevel1 && maliat <= maliatlevel2)
		daramad = round((maliat+ 1500000) /0.20);
	else if (maliat > maliatlevel2 && maliat <= maliatlevel3)
		daramad = round((maliat+ 6500000) /0.25);
	else if (maliat > maliatlevel3 && maliat <= maliatlevel4)
		daramad = round((maliat+ 19000000) /0.30);
	else if (maliat > maliatlevel4)
		daramad = round((maliat+ 69000000) /0.35);

	return daramad;
}
//*********************************************************************
//محاسبه درآمد قدیم با اصناف
long long int Momayez::daramad131oldAsnaf(long long int maliat)
{//تکمیل
	long long maliatlevel1= 4525500;
	long long maliatlevel2= 18581500;
	long long maliatlevel3= 56194000;
	long long maliatlevel4= 281719000;

	long long int daramad;
	if (maliat <= maliatlevel1)
		daramad = round(maliat / 0.15085);
	else if (maliat > maliatlevel1 && maliat <= maliatlevel2)
		daramad = round((maliat + 1500000) / 0.2008);
	else if (maliat > maliatlevel2 && maliat <= maliatlevel3)
		daramad = round((maliat + 6500000) / 0.25075);
	else if (maliat > maliatlevel3 && maliat <= maliatlevel4)
		daramad = round((maliat + 19000000) / 0.3007);
	else if (maliat > maliatlevel4)
		daramad = round((maliat + 69000000) / 0.35065);

	return daramad;
}
//*********************************************************************
//محاسبه درآمد جدید
long long int Momayez::daramad131new(long long int maliat, int takhfif)
{//تکمیل
	long long int daramad;
 	
	//ضریب سقف های تغییریافته ماده 131 جدید
	double zaribnewChangedlevel1 = 0.15;
	//ضریب سقف های تغییریافته ماده 131 جدید
	double zaribnewChangedlevel2 = 0.20;
	//ضریب سقف های تغییریافته ماده 131 جدید
	double zaribnewChangedlevel3 = 0.25;

	//محاسبه حد مقایسه
	long long hadlevel1 = round(newlevel1 * zaribnewChangedlevel1) ;
	long long hadlevel2 = round((newlevel1 * zaribnewChangedlevel1)) + round(((newlevel2 - newlevel1) * zaribnewChangedlevel2)) ;

	switch (takhfif)//اعمال تخفیف تبصره ماده 131 جدید
	{
	case 0://تخفیف صفر درصد
		break;
	case 1://تخفیف یک درصد
		zaribnewChangedlevel1 -= 0.01;
		zaribnewChangedlevel2 -= 0.01;
		zaribnewChangedlevel3 -= 0.01;
		hadlevel1 = round(newlevel1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((newlevel1 * zaribnewChangedlevel1)) + round(((newlevel2 - newlevel1) * zaribnewChangedlevel2)) ;
		break;
	case 2://تخفیف دو درصد
		zaribnewChangedlevel1 -= 0.02;
		zaribnewChangedlevel2 -= 0.02;
		zaribnewChangedlevel3 -= 0.02;
		hadlevel1 = round(newlevel1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((newlevel1 * zaribnewChangedlevel1)) + round(((newlevel2 - newlevel1) * zaribnewChangedlevel2)) ;
		break;
	case 3://تخفیف سه درصد
		zaribnewChangedlevel1 -= 0.03;
		zaribnewChangedlevel2 -= 0.03;
		zaribnewChangedlevel3 -= 0.03;
		hadlevel1 = round(newlevel1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((newlevel1 * zaribnewChangedlevel1)) + round(((newlevel2 - newlevel1) * zaribnewChangedlevel2)) ;
		break;
	case 4://تخفیف چهار درصد
		zaribnewChangedlevel1 -= 0.04;
		zaribnewChangedlevel2 -= 0.04;
		zaribnewChangedlevel3 -= 0.04;
		hadlevel1 = round(newlevel1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((newlevel1 * zaribnewChangedlevel1)) + round(((newlevel2 - newlevel1) * zaribnewChangedlevel2)) ;
		break;
	case 5://تخفیف پنج درصد
		zaribnewChangedlevel1 -= 0.05;
		zaribnewChangedlevel2 -= 0.05;
		zaribnewChangedlevel3 -= 0.05;
		hadlevel1 = round(newlevel1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((newlevel1 * zaribnewChangedlevel1)) + round(((newlevel2 - newlevel1) * zaribnewChangedlevel2)) ;
		break;
	}

	if (maliat <= hadlevel1)
		daramad = round(maliat / zaribnewChangedlevel1);
	else if (maliat > hadlevel1 && maliat <= hadlevel2)
		daramad = round((maliat + 25000000) / zaribnewChangedlevel2);
	else if (maliat > hadlevel2)
		daramad = round((maliat + 75000000) / zaribnewChangedlevel3);

	return daramad;

}
//*********************************************************************
//محاسبه درآمد جدید با اصناف
long long int Momayez::daramad131newAsnaf(long long int maliat, int takhfif)
{//تکمیل
	long long int daramad;
	
	double zaribnewChangedlevel1 = 0.15085;
	double zaribnewChangedlevel2 = 0.2008;
	double zaribnewChangedlevel3 = 0.25075;

	//محاسبه حد مقایسه
	long long hadlevel1 = round(newlevel1 * zaribnewChangedlevel1) ;
	long long hadlevel2 = round((newlevel1 * zaribnewChangedlevel1)) + round(((newlevel2 - newlevel1) * zaribnewChangedlevel2)) ;

	switch (takhfif)//اعمال تخفیف تبصره ماده 131 جدید
	{
	case 0://تخفیف صفر درصد
		break;
	case 1://تخفیف یک درصد
		zaribnewChangedlevel1 = 0.14086;
		zaribnewChangedlevel2 = 0.19081;
		zaribnewChangedlevel3 = 0.24076;
		hadlevel1 = round(newlevel1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((newlevel1 * zaribnewChangedlevel1)) + round(((newlevel2 - newlevel1) * zaribnewChangedlevel2)) ;
		break;
	case 2://تخفیف دو درصد
		zaribnewChangedlevel1 = 0.13087;
		zaribnewChangedlevel2 = 0.18082;
		zaribnewChangedlevel3 = 0.23077;
		hadlevel1 = round(newlevel1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((newlevel1 * zaribnewChangedlevel1)) + round(((newlevel2 - newlevel1) * zaribnewChangedlevel2)) ;
		break;
	case 3://تخفیف سه درصد
		zaribnewChangedlevel1 = 0.12088;
		zaribnewChangedlevel2 = 0.17083;
		zaribnewChangedlevel3 = 0.22078;
		hadlevel1 = round(newlevel1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((newlevel1 * zaribnewChangedlevel1)) + round(((newlevel2 - newlevel1) * zaribnewChangedlevel2)) ;
		break;
	case 4://تخفیف چهار درصد
		zaribnewChangedlevel1 = 0.11089;
		zaribnewChangedlevel2 = 0.16084;
		zaribnewChangedlevel3 = 0.21079;
		hadlevel1 = round(newlevel1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((newlevel1 * zaribnewChangedlevel1)) + round(((newlevel2 - newlevel1) * zaribnewChangedlevel2)) ;
		break;
	case 5://تخفیف پنج درصد
		zaribnewChangedlevel1 = 0.10090;
		zaribnewChangedlevel2 = 0.15085;
		zaribnewChangedlevel3 = 0.20080;
		hadlevel1 = round(newlevel1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((newlevel1 * zaribnewChangedlevel1)) + round(((newlevel2 - newlevel1) * zaribnewChangedlevel2)) ;
		break;
	}
	
	if (maliat <= hadlevel1)
		daramad = round(maliat / zaribnewChangedlevel1);
	else if (maliat > hadlevel1 && maliat <= hadlevel2)
		daramad = round((maliat + 25000000) / zaribnewChangedlevel2);
	else if (maliat > hadlevel2)
		daramad = round((maliat + 75000000) / zaribnewChangedlevel3);

	return daramad;

}
//*********************************************************************
//محاسبه درآمد 1401
long long int Momayez::daramad1311401(long long int maliat, int takhfif)
{//تکمیل
	long long int daramad;
	//ضریب سقف های تغییریافته ماده 131 جدید
	double zaribnewChangedlevel1 = 0.15;
	//ضریب سقف های تغییریافته ماده 131 جدید
	double zaribnewChangedlevel2 = 0.20;
	//ضریب سقف های تغییریافته ماده 131 جدید
	double zaribnewChangedlevel3 = 0.25;

	//محاسبه حد مقایسه
	long long hadlevel1 = round(new1401level1 * zaribnewChangedlevel1) ;
	long long hadlevel2 = round((new1401level1 * zaribnewChangedlevel1)) + round(((new1401level2 - new1401level1) * zaribnewChangedlevel2));

	switch (takhfif)//اعمال تخفیف تبصره ماده 131 جدید
	{
	case 0://تخفیف صفر درصد
		break;
	case 1://تخفیف یک درصد
		zaribnewChangedlevel1 -= 0.01;
		zaribnewChangedlevel2 -= 0.01;
		zaribnewChangedlevel3 -= 0.01;
		hadlevel1 = round(new1401level1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((new1401level1 * zaribnewChangedlevel1)) + round(((new1401level2 - new1401level1) * zaribnewChangedlevel2));
		break;
	case 2://تخفیف دو درصد
		zaribnewChangedlevel1 -= 0.02;
		zaribnewChangedlevel2 -= 0.02;
		zaribnewChangedlevel3 -= 0.02;
		hadlevel1 = round(new1401level1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((new1401level1 * zaribnewChangedlevel1)) + round(((new1401level2 - new1401level1) * zaribnewChangedlevel2));
		break;
	case 3://تخفیف سه درصد
		zaribnewChangedlevel1 -= 0.03;
		zaribnewChangedlevel2 -= 0.03;
		zaribnewChangedlevel3 -= 0.03;
		hadlevel1 = round(new1401level1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((new1401level1 * zaribnewChangedlevel1)) + round(((new1401level2 - new1401level1) * zaribnewChangedlevel2));
		break;
	case 4://تخفیف چهار درصد
		zaribnewChangedlevel1 -= 0.04;
		zaribnewChangedlevel2 -= 0.04;
		zaribnewChangedlevel3 -= 0.04;
		hadlevel1 = round(new1401level1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((new1401level1 * zaribnewChangedlevel1)) + round(((new1401level2 - new1401level1) * zaribnewChangedlevel2));
		break;
	case 5://تخفیف پنج درصد
		zaribnewChangedlevel1 -= 0.05;
		zaribnewChangedlevel2 -= 0.05;
		zaribnewChangedlevel3 -= 0.05;
		hadlevel1 = round(new1401level1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((new1401level1 * zaribnewChangedlevel1)) + round(((new1401level2 - new1401level1) * zaribnewChangedlevel2));
		break;
	}

	if (maliat <= hadlevel1)
		daramad = round(maliat / zaribnewChangedlevel1);
	else if (maliat > hadlevel1 && maliat <= hadlevel2)
		daramad = round((maliat + 100000000) / zaribnewChangedlevel2);
	else if (maliat > hadlevel2)
		daramad = round((maliat + 300000000) / zaribnewChangedlevel3);

	return daramad;

}
//*********************************************************************
//محاسبه درآمد 1401 با اصناف
long long int Momayez::daramad1311401Asnaf(long long int maliat, int takhfif)
{//تکمیل
	long long int daramad;
	double zaribnewChangedlevel1 = 0.15085;
	double zaribnewChangedlevel2 = 0.2008;
	double zaribnewChangedlevel3 = 0.25075;

	//محاسبه حد مقایسه
	long long hadlevel1 = round(new1401level1 * zaribnewChangedlevel1) ;
	long long hadlevel2 = round((new1401level1 * zaribnewChangedlevel1)) + round(((new1401level2 - new1401level1) * zaribnewChangedlevel2));

	switch (takhfif)//اعمال تخفیف تبصره ماده 131 جدید
	{
	case 0://تخفیف صفر درصد
		break;
	case 1://تخفیف یک درصد
		zaribnewChangedlevel1 = 0.14086;
		zaribnewChangedlevel2 = 0.19081;
		zaribnewChangedlevel3 = 0.24076;
		hadlevel1 = round(new1401level1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((new1401level1 * zaribnewChangedlevel1)) + round(((new1401level2 - new1401level1) * zaribnewChangedlevel2));
		break;
	case 2://تخفیف دو درصد
		zaribnewChangedlevel1 = 0.13087;
		zaribnewChangedlevel2 = 0.18082;
		zaribnewChangedlevel3 = 0.23077;
		hadlevel1 = round(new1401level1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((new1401level1 * zaribnewChangedlevel1)) + round(((new1401level2 - new1401level1) * zaribnewChangedlevel2));
		break;
	case 3://تخفیف سه درصد
		zaribnewChangedlevel1 = 0.12088;
		zaribnewChangedlevel2 = 0.17083;
		zaribnewChangedlevel3 = 0.22078;
		hadlevel1 = round(new1401level1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((new1401level1 * zaribnewChangedlevel1)) + round(((new1401level2 - new1401level1) * zaribnewChangedlevel2));
		break;
	case 4://تخفیف چهار درصد
		zaribnewChangedlevel1 = 0.11089;
		zaribnewChangedlevel2 = 0.16084;
		zaribnewChangedlevel3 = 0.21079;
		hadlevel1 = round(new1401level1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((new1401level1 * zaribnewChangedlevel1)) + round(((new1401level2 - new1401level1) * zaribnewChangedlevel2));
		break;
	case 5://تخفیف پنج درصد
		zaribnewChangedlevel1 = 0.10090;
		zaribnewChangedlevel2 = 0.15085;
		zaribnewChangedlevel3 = 0.20080;
		hadlevel1 = round(new1401level1 * zaribnewChangedlevel1) ;
		hadlevel2 = round((new1401level1 * zaribnewChangedlevel1)) + round(((new1401level2 - new1401level1) * zaribnewChangedlevel2));
		break;
	}
	
	if (maliat <= hadlevel1)
		daramad = round(maliat / zaribnewChangedlevel1);
	else if (maliat > hadlevel1 && maliat <= hadlevel2)
		daramad = round((maliat + 100000000) / zaribnewChangedlevel2);
	else if (maliat > hadlevel2)
		daramad = round((maliat + 300000000) / zaribnewChangedlevel3);

	return daramad;

}
//*********************************************************************
//محاسبه مالیات قدیم
long long int Momayez::maliat131old(long long int daramad)
{//تکمیل
	long long int maliat;
	if (daramad <= oldlevel1)
		maliat = round(daramad*zariboldlevel1);
	else if (daramad > oldlevel1 && daramad <= oldlevel2)
		maliat = round((daramad*zariboldlevel2) - 1500000);
	else if(daramad > oldlevel2 && daramad <= oldlevel3)
		maliat = round((daramad*zariboldlevel3) - 6500000);
	else if (daramad > oldlevel3 && daramad <= oldlevel4)
		maliat = round((daramad*zariboldlevel4) - 19000000);
	else if (daramad > oldlevel4)
		maliat = round((daramad*zariboldlevel5) - 69000000);
	
	return maliat;
}
//*********************************************************************
//محاسبه مالیات جدید
long long int Momayez::maliat131new(long long int daramad, int takhfif)
{//تکمیل

 //ضریب سقف های تغییریافته ماده 131 جدید
	double zaribnewChangedlevel1 = 0.15;
	//ضریب سقف های تغییریافته ماده 131 جدید
	double zaribnewChangedlevel2 = 0.20;
	//ضریب سقف های تغییریافته ماده 131 جدید
	double zaribnewChangedlevel3 = 0.25;

	switch (takhfif)//اعمال تخفیف تبصره ماده 131 جدید
	{
	case 0://تخفیف صفر درصد
		break;
	case 1://تخفیف یک درصد
		zaribnewChangedlevel1 -= 0.01;
		zaribnewChangedlevel2 -= 0.01;
		zaribnewChangedlevel3 -= 0.01;
		break;
	case 2://تخفیف دو درصد
		zaribnewChangedlevel1 -= 0.02;
		zaribnewChangedlevel2 -= 0.02;
		zaribnewChangedlevel3 -= 0.02;
		break;
	case 3://تخفیف سه درصد
		zaribnewChangedlevel1 -= 0.03;
		zaribnewChangedlevel2 -= 0.03;
		zaribnewChangedlevel3 -= 0.03;
		break;
	case 4://تخفیف چهار درصد
		zaribnewChangedlevel1 -= 0.04;
		zaribnewChangedlevel2 -= 0.04;
		zaribnewChangedlevel3 -= 0.04;
		break;
	case 5://تخفیف پنج درصد
		zaribnewChangedlevel1 -= 0.05;
		zaribnewChangedlevel2 -= 0.05;
		zaribnewChangedlevel3 -= 0.05;
		break;
	}
	

	long long int maliat;
	if (daramad <= newlevel1)
		maliat = round(daramad*zaribnewChangedlevel1);
	else if (daramad > newlevel1 && daramad <= newlevel2)
	maliat = round((daramad*zaribnewChangedlevel2)) - 25000000;
	else if (daramad > newlevel2)
	maliat = round((daramad*zaribnewChangedlevel3)) - 75000000;
	

	return maliat;

}
//*********************************************************************
//محاسبه مالیات 1401
long long int Momayez::maliat1311401(long long int daramad, int takhfif)
{//تکمیل

 //ضریب سقف های تغییریافته ماده 131 جدید
	double zaribnewChangedlevel1 = 0.15;
	//ضریب سقف های تغییریافته ماده 131 جدید
	double zaribnewChangedlevel2 = 0.20;
	//ضریب سقف های تغییریافته ماده 131 جدید
	double zaribnewChangedlevel3 = 0.25;

	switch (takhfif)//اعمال تخفیف تبصره ماده 131 جدید
	{
	case 0://تخفیف صفر درصد
		break;
	case 1://تخفیف یک درصد
		zaribnewChangedlevel1 -= 0.01;
		zaribnewChangedlevel2 -= 0.01;
		zaribnewChangedlevel3 -= 0.01;
		break;
	case 2://تخفیف دو درصد
		zaribnewChangedlevel1 -= 0.02;
		zaribnewChangedlevel2 -= 0.02;
		zaribnewChangedlevel3 -= 0.02;
		break;
	case 3://تخفیف سه درصد
		zaribnewChangedlevel1 -= 0.03;
		zaribnewChangedlevel2 -= 0.03;
		zaribnewChangedlevel3 -= 0.03;
		break;
	case 4://تخفیف چهار درصد
		zaribnewChangedlevel1 -= 0.04;
		zaribnewChangedlevel2 -= 0.04;
		zaribnewChangedlevel3 -= 0.04;
		break;
	case 5://تخفیف پنج درصد
		zaribnewChangedlevel1 -= 0.05;
		zaribnewChangedlevel2 -= 0.05;
		zaribnewChangedlevel3 -= 0.05;
		break;
	}
	

	long long int maliat;
	if (daramad <= new1401level1)
		maliat = round(daramad*zaribnewChangedlevel1);
	else if (daramad > new1401level1 && daramad <= new1401level2)
	maliat = round((daramad*zaribnewChangedlevel2)) - 100000000;
	else if (daramad > new1401level2)
	maliat = round((daramad*zaribnewChangedlevel3)) - 300000000;
	

	return maliat;

}
//*********************************************************************
long long int Momayez::tambr(long long int maliat)//حق تمبر وکیل
{
		if(maliat<400000000)
			return maliat * 0.05 * 0.05 ;
		else if(maliat>400000000 && maliat<1200000000)
			return ((maliat-400000000) * 0.04 * 0.05) + 1000000;
		else if(maliat>1200000000)
			return ((maliat-1200000000) * 0.03 * 0.05) + 2600000;
}
//*********************************************************************
long long int Momayez::maliateidi1401(long long int eidi, long long int hoghoogh)//مالیات عیدی سال 1401
{
	long long mashmooleidi = eidi - (moafiath1401/12);
	long long mashmoolkol = mashmooleidi + hoghoogh;
	long long nesab = moafiath1401 * 8;
	if(mashmoolkol > nesab){
		long long int big = (mashmoolkol - nesab) * 0.20;
		long long int small = (mashmooleidi - (mashmoolkol - nesab)) * 0.10 ;
		return big + small ;
		}
	else{
		return mashmooleidi * 0.10 ;
		}
}
//*********************************************************************
long long int Momayez::maliathoghoogh1401(long long int hoghoogh )//مالیات حقوق سال 1401
{
	long long int maliat=0;
	if (hoghoogh <= moafiath1401)
		maliat = 0;
	else if (hoghoogh > moafiath1401 && hoghoogh <= 1800000000)
		maliat = hoghoogh * 0.10;
	else if (hoghoogh > 1800000000 && hoghoogh <= 3000000000)
		maliat = ((hoghoogh-1800000000) * 0.15) + 180000000 ;
	else if (hoghoogh > 3000000000 && hoghoogh <= 4200000000)
		maliat = ((hoghoogh-3000000000) * 0.20) + 360000000 ;
	else if (hoghoogh > 4200000000)
		maliat = ((hoghoogh-4200000000) * 0.30) + 600000000 ;

	return maliat;
}
