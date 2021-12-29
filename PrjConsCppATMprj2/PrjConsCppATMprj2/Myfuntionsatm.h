#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include <iomanip>

using namespace std;
//Structure declaration
struct account
{
	string number;
	string name;
	string pin;
	float balance;
};

//Global variable declaration
account tabaccinfos[200];

//This funtion Display underlined Titles
//------------------------------------------------------------------------
void DisplayTitles(string Title)
{
	cout << "\t";

	for (int i = 0; i < Title.length(); i++)
	{
		cout << char(toupper(Title[i]));
	}
	cout << "\n\t";
	for (int i = 0; i < Title.length(); i++)
	{
		cout << "-";
	}
	cout << "\n";
}

//This funtion read all the accounts in the text file
//------------------------------------------------------------------------
int ReadAllAccounts()
{
	ifstream MyFile;
	int i = 0;
	MyFile.open("ATMregisteredacc.txt");

	while (MyFile.eof() == false)
	{
		string temp;

		getline(MyFile, tabaccinfos[i].number);
		getline(MyFile, tabaccinfos[i].name);
		getline(MyFile, tabaccinfos[i].pin);
		MyFile >> temp;
		tabaccinfos[i].balance = stof(temp);
		MyFile.ignore();
		i++;
	}
	MyFile.close();
	return i;
}

//This funtion search the account index when the user introduce their accoun number
//------------------------------------------------------------------------
int findAccount(int nbaccount)
{
	string nrocomte;
	bool found = false;
	cout << endl;
	do {
		cout << "Entrez votre numero de compte: ";
		cin >> nrocomte;

		for (int i = 0; i < nbaccount; i++)
		{
			if (tabaccinfos[i].number == nrocomte)
			{
				return i;
			}
		}
		found = false;
	} while (found == false);
}

//This funtion display the name according the account index 
//------------------------------------------------------------------------
void DisplayClientName(int accountindex)
{
	string greeting;
	cout << "\n\tBienvenue " << tabaccinfos[accountindex].name << endl;

}

//This funtion display the transaction pannel 
//------------------------------------------------------------------------
void TransactionPanel(int opt1st, int opt2, int optlast)
{
	cout << endl;
	cout << "Choisir votre Transaction\n";
	cout << "\t" << opt1st << " - Pour Deposer\n";
	cout << "\t" << opt2 << " - Pour Retirer\n";
	cout << "\t" << optlast << " - Pour Consulter\n";
}

//This funtion compare the pin number in the text file with the pin number that the user introduce in the program 
//----------------------------------------------------------------------------------------------------------------------
void PinValidation(int accountindex)
{
	string nip, invalidpin = "Invalid";
	do {
		cout << "Entrez votre nip: ";
		cin >> nip;

		if (tabaccinfos[accountindex].pin == nip)
		{
			TransactionPanel(1, 2, 3);
			invalidpin = "valid";
		}
		else(cout << "Nip non valide\n");


	} while (invalidpin == "Invalid");
	cout << endl;
}

//This funtion read the choice make for the user
//------------------------------------------------------------------------
int ReadChoice(int opt1st, int optlast)
{
	int nbtransactiontype;
	do {
		cout << "Entrez votre choix ( " << opt1st << " - " << optlast << " ) :";
		cin >> nbtransactiontype;
	} while (nbtransactiontype<opt1st || nbtransactiontype>optlast);
	return nbtransactiontype;
}

//This funtion is for the case 1 deposit  
//------------------------------------------------------------------------
int case1Deposer(int min, int max, int accountindex)
{
	int deposit;
	float accountbalace = tabaccinfos[accountindex].balance;
	float newbalance;
	cout << "\nEntrez le montant a deposer $ :";
	cin >> deposit;
	while (deposit < min || deposit>max)
	{
		cout << "\nEntrez le montant a deposer $ (Min " << min << " $ -  Max " << max << " $) :";
		cin >> deposit;
	}
	cout << endl;
	newbalance = accountbalace + deposit;

	return newbalance;
}

//This funtion is for the case 2 Withdraw
//------------------------------------------------------------------------
int case2Withdrawal(int min, int max, int multiple, int accountindex)
{
	int withdrawal;
	float accountbalace = tabaccinfos[accountindex].balance;
	float newbalance;
	cout << "\nEntrez le montant a retirer $ :";
	cin >> withdrawal;
	while (withdrawal < min || withdrawal>max || withdrawal > accountbalace || withdrawal % multiple != 0)
	{
		if (withdrawal < min || withdrawal>max)
		{
			cout << "Entrez le montant a retirer $ (Min " << min << " $ -  Max " << max << " $) :";
			cin >> withdrawal;
		}
		else if (withdrawal % multiple != 0)
		{
			cout << "Entrez le montant a retirer $ (le montant doit etre un multiple de " << multiple << " ):";
			cin >> withdrawal;
		}
		else if (withdrawal > accountbalace)
		{
			cout << "Solde insuffisant,\nEssayez un nouveau montant :";
			cin >> withdrawal;
		}
	}
	cout << endl;
	newbalance = accountbalace - withdrawal;

	return  newbalance;
}

//This funtion write the new balance in the text file (user account) 
//------------------------------------------------------------------------
void WriteNewBalance(int accountindex, int nbaccount, float totalbalance)
{
	int i = 0;
	ofstream MyFile;
	MyFile.open("ATMregisteredacc.txt");

	while (i < nbaccount)
	{
		MyFile << fixed << setprecision(2);

		if (i == accountindex)
		{
			MyFile << tabaccinfos[accountindex].number << endl;
			MyFile << tabaccinfos[accountindex].name << endl;
			MyFile << tabaccinfos[accountindex].pin << endl;
			if (i < (nbaccount - 1))
			{
				MyFile << (tabaccinfos[accountindex].balance = totalbalance) << endl;
			}
			else { MyFile << (tabaccinfos[accountindex].balance= totalbalance); }
		}

		else {
			MyFile << tabaccinfos[i].number << endl;
			MyFile << tabaccinfos[i].name << endl;
			MyFile << tabaccinfos[i].pin << endl;
			if (i < (nbaccount - 1))
			{
				MyFile << tabaccinfos[i].balance << endl;
			}
			else { MyFile << tabaccinfos[i].balance; }
		}
		i++;
	}
	MyFile.close();
}

//This funtion display the account information
//------------------------------------------------------------------------
void Displayaccountinfo(int accountindex)
{
	cout << fixed << setprecision(2);
	cout << endl;
	cout << "Les infos du compte";
	cout << "\n\tNumero  : " << tabaccinfos[accountindex].number;
	cout << "\n\tClient  : " << tabaccinfos[accountindex].name;
	cout << "\n\tNip     : " << tabaccinfos[accountindex].pin;
	cout << "\n\tSolde $ : " << tabaccinfos[accountindex].balance << endl;
	cout << endl << endl;

}

//This funtion display subtitles(First letter in uppercase")
//------------------------------------------------------------------------
void DisplaySubtitles(string subtitle)
{
	cout << char(toupper(subtitle[0]));

	for (int i = 1; i < subtitle.length(); i++)
	{
		cout << char(tolower(subtitle[i]));
	}
	cout << "\n";
}

//This funtion display the copyrigth 
//------------------------------------------------------------------------
void HastaLaVista()
{
	system("cls");
	cout << "\n\n\n\t    This program was build by Albelis Becea\n\n\n\n\t\tThank you for using my program\n\n\n\n\t  All the rigth belong to Albelis Becea ID 2110083\n\n\n\n";
	system("pause");
}