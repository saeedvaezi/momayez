#include "Momayez.h"

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
				asnafprice = asnaf131(mablagh);
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
				asnafprice = asnaf131(mablagh);
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
}

//محاسبه حق اصناف
long long int Momayez::asnaf131(long long int daramad)
{
	return daramad*0.001;
}

//محاسبه درآمد قدیم
long long int Momayez::daramad131old(long long int maliat)
{//تکمیل
	long long int daramad;
	if (maliat <= oldlevel1)
		daramad = maliat/0.15;
	else if (maliat > oldlevel1 && maliat <= oldlevel2)
		daramad = (maliat+ 1500000) /0.20;
	else if (maliat > oldlevel2 && maliat <= oldlevel3)
		daramad = (maliat+ 6500000) /0.25;
	else if (maliat > oldlevel3 && maliat <= oldlevel4)
		daramad = (maliat+ 19000000) /0.30;
	else if (maliat > oldlevel4)
		daramad = (maliat+ 69000000) /0.35;

	return daramad;
}

//محاسبه درآمد قدیم با اصناف
long long int Momayez::daramad131oldAsnaf(long long int maliat)
{//تکمیل
	long long int daramad;
	if (maliat <= oldlevel1)
		daramad = maliat / 0.15085;
	else if (maliat > oldlevel1 && maliat <= oldlevel2)
		daramad = (maliat + 1500000) / 0.2008;
	else if (maliat > oldlevel2 && maliat <= oldlevel3)
		daramad = (maliat + 6500000) / 0.25075;
	else if (maliat > oldlevel3 && maliat <= oldlevel4)
		daramad = (maliat + 19000000) / 0.3007;
	else if (maliat > oldlevel4)
		daramad = (maliat + 69000000) / 0.35065;

	return daramad;
}

//محاسبه درآمد جدید
long long int Momayez::daramad131new(long long int maliat, int takhfif)
{//تکمیل
	long long int daramad;
	switch (takhfif)//اعمال تخفیف تبصره ماده 131 جدید
	{
	case 0://تخفیف صفر درصد
		if (maliat <= newlevel1)
			daramad = maliat / 0.15;
		else if (maliat > newlevel1 && maliat <= newlevel2)
			daramad = (maliat + 25000000) / 0.20;
		else if (maliat > newlevel2)
			daramad = (maliat + 75000000) / 0.25;
		break;

	case 1://تخفیف یک درصد
		if (maliat <= newlevel1)
			daramad = maliat / 0.14;
		else if (maliat > newlevel1 && maliat <= newlevel2)
			daramad = (maliat + 25000000) / 0.19;
		else if (maliat > newlevel2)
			daramad = (maliat + 75000000) / 0.24;
		break;

	case 2://تخفیف دو درصد
		if (maliat <= newlevel1)
			daramad = maliat / 0.13;
		else if (maliat > newlevel1 && maliat <= newlevel2)
			daramad = (maliat + 25000000) / 0.18;
		else if (maliat > newlevel2)
			daramad = (maliat + 75000000) / 0.23;
		break;

	case 3://تخفیف سه درصد
		if (maliat <= newlevel1)
			daramad = maliat / 0.12;
		else if (maliat > newlevel1 && maliat <= newlevel2)
			daramad = (maliat + 25000000) / 0.17;
		else if (maliat > newlevel2)
			daramad = (maliat + 75000000) / 0.22;
		break;

	case 4://تخفیف چهار درصد
		if (maliat <= newlevel1)
			daramad = maliat / 0.11;
		else if (maliat > newlevel1 && maliat <= newlevel2)
			daramad = (maliat + 25000000) / 0.16;
		else if (maliat > newlevel2)
			daramad = (maliat + 75000000) / 0.21;
		break;

	case 5://تخفیف پنج درصد
		if (maliat <= newlevel1)
			daramad = maliat / 0.10;
		else if (maliat > newlevel1 && maliat <= newlevel2)
			daramad = (maliat + 25000000) / 0.15;
		else if (maliat > newlevel2)
			daramad = (maliat + 75000000) / 0.20;
		break;
	}

	return daramad;

}

//محاسبه درآمد جدید با اصناف
long long int Momayez::daramad131newAsnaf(long long int maliat, int takhfif)
{//تکمیل
	long long int daramad;
	switch (takhfif)//اعمال تخفیف تبصره ماده 131 جدید
	{
	case 0://تخفیف صفر درصد
		if (maliat <= newlevel1)
			daramad = maliat / 0.15085;
		else if (maliat > newlevel1 && maliat <= newlevel2)
			daramad = (maliat + 25000000) / 0.2008;
		else if (maliat > newlevel2)
			daramad = (maliat + 75000000) / 0.25075;
		break;

	case 1://تخفیف یک درصد
		if (maliat <= newlevel1)
			daramad = maliat / 0.14086;
		else if (maliat > newlevel1 && maliat <= newlevel2)
			daramad = (maliat + 25000000) / 0.19081;
		else if (maliat > newlevel2)
			daramad = (maliat + 75000000) / 0.24076;
		break;

	case 2://تخفیف دو درصد
		if (maliat <= newlevel1)
			daramad = maliat / 0.13087;
		else if (maliat > newlevel1 && maliat <= newlevel2)
			daramad = (maliat + 25000000) / 0.18082;
		else if (maliat > newlevel2)
			daramad = (maliat + 75000000) / 0.23077;
		break;

	case 3://تخفیف سه درصد
		if (maliat <= newlevel1)
			daramad = maliat / 0.12088;
		else if (maliat > newlevel1 && maliat <= newlevel2)
			daramad = (maliat + 25000000) / 0.17083;
		else if (maliat > newlevel2)
			daramad = (maliat + 75000000) / 0.22078;
		break;

	case 4://تخفیف چهار درصد
		if (maliat <= newlevel1)
			daramad = maliat / 0.11089;
		else if (maliat > newlevel1 && maliat <= newlevel2)
			daramad = (maliat + 25000000) / 0.16084;
		else if (maliat > newlevel2)
			daramad = (maliat + 75000000) / 0.21079;
		break;

	case 5://تخفیف پنج درصد
		if (maliat <= newlevel1)
			daramad = maliat / 0.1009;
		else if (maliat > newlevel1 && maliat <= newlevel2)
			daramad = (maliat + 25000000) / 0.15085;
		else if (maliat > newlevel2)
			daramad = (maliat + 75000000) / 0.2008;
		break;
	}

	return daramad;

}

//محاسبه مالیات قدیم
long long int Momayez::maliat131old(long long int daramad)
{//تکمیل
	long long int maliat;
	if (daramad <= oldlevel1)
		maliat = daramad*zariboldlevel1;
	else if (daramad > oldlevel1 && daramad <= oldlevel2)
		maliat = (daramad*zariboldlevel2) - 1500000;
	else if(daramad > oldlevel2 && daramad <= oldlevel3)
		maliat = (daramad*zariboldlevel3) - 6500000;
	else if (daramad > oldlevel3 && daramad <= oldlevel4)
		maliat = (daramad*zariboldlevel4) - 19000000;
	else if (daramad > oldlevel4)
		maliat = (daramad*zariboldlevel5) - 69000000;
	
	return maliat;
}

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
		maliat = daramad*zaribnewChangedlevel1;
	else if (daramad > newlevel1 && daramad <= newlevel2)
	maliat = (daramad*zaribnewChangedlevel2) - 25000000;
	else if (daramad > newlevel2)
	maliat = (daramad*zaribnewChangedlevel3) - 75000000;
	

	return maliat;

}
