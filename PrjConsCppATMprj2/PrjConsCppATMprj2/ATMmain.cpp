#include"Myfuntionsatm.h"

int main()
{
	int nbaccount, choice, Newbalcase = 0;
	int accountindex;



	DisplayTitles("         bank Royale        ");
	DisplayTitles("Guichet Automatique Bancaire");
	nbaccount = ReadAllAccounts();

	accountindex = findAccount(nbaccount);
	DisplayClientName(accountindex);
	PinValidation(accountindex);
	choice = ReadChoice(1, 3);

	switch (choice)
	{
	case 1:
		Newbalcase = case1Deposer(2, 20000, accountindex);

		WriteNewBalance(accountindex, nbaccount, Newbalcase);
		if (Newbalcase)
		{
			DisplaySubtitles("---la transaction a reussi---");
		}
		Displayaccountinfo(accountindex);
		break;
	case 2:
		Newbalcase = case2Withdrawal(20, 500, 20, accountindex);

		WriteNewBalance(accountindex, nbaccount, Newbalcase);
		if (Newbalcase)
		{
			DisplaySubtitles("---la transaction a reussi---");
		}
		Displayaccountinfo(accountindex);
		break;
	case 3:
		Displayaccountinfo(accountindex);
		break;
	}

	DisplaySubtitles("mERCI d'avoir utiliser nos services");
	DisplaySubtitles("Appuyez sur une touche pour Continuer...");
	system("pause");

	short copyrigth = 1;
	if (copyrigth) { HastaLaVista(); }

	return 0;
}