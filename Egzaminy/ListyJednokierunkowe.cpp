struct lista
{
	int jakaswartosc;
	lista * next;
};

void UsunJednoWybrane(lista *&head, int szukanawartosc)
{
	lista *tmp;
	lista *first;
	if(head->jakaswartosc == szukanawartosc)				// przypadek z usuwaniem I elementu
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
	else
	{
		first = head;
		while(head->next)
		{
			if(head->next->jakaswartosc == szukanawartosc)	// reszta przypadk�w
			{
				tmp = head;
				head = head->next;
				tmp->next = head->next;
				delete head;
			}
		}
		head = tmp;
	}
}

void UsunWszystko(lista *& head)
{
	while (head)
	{
		lista * tmp = head->next;
		delete head;
		head = tmp;
	}
}

void DodajNaPoczatku(lista *& head, int dane)
{
	if(head == nullptr)										// przypadek z pust� list�
	{
		head = new lista {dane, nullptr};
	}
	else													// przypadek z niepust� list�
	{
		head = new lista{head, nullptr};
	}
}

void DodajUporzadkowanie(lista *&head, int dane)			// b�d� dodawa� do listy uporz�dkowanej niemalej�co czyli np. 1 1 2 5 10 12 12 12 15
{
	lista *tmpFirst = head;
	if(head == nullptr)										// przypadek z dodawaniem do pustej listy
	{
		head = new lista{dane, nullptr};
	}
	else if(dane <= head->jakaswartosc)						// przypadek z dodawaniem na pocz�tek listy 
	{
		head = new lista{dane, head};
	}
	else
	{
		while(head)
		{
			if(head->next && dane > head->next->jakaswartosc)	head = head->next;		
			else if(head->next == nullptr)					// przypadek z dodawaniem na koncu listy
			{
				head->next = new lista{dane, nullptr};
			}
			else
			{
				head->next = new lista{dae, head->next};	// przypadek z dodawaniem w srodku listy
			}
		}
		head = tmpFirst;
	}
}

int PoliczIloscElementow(lista *head)
{
	int ilosc = 0;
	while(head)
	{
		ilosc++;
		head = head->next;
	}
	return ilosc;
}
