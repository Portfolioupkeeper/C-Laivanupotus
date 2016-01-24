/*

1.  Tampereen ammattikorkeakoulu, G-02019-2018, Ohjelmointi 2 ja 2013
2.	Laivanupotus
3.	Toni Manninen, Anssi Sorsakivi, 11i224 / ???
4.	toni.manninen@eng.tamk.fi / anssi.sorsakivi@pe.tamk.fi
5.	työn tekemiseen kulunut aika tunteina: n.20h
6.	luettelo ohjelman sisältämistä lisäominaisuuksista: perustoiminnot, 1a, 1b, 2c, 2d

Ohjelman tarkoituksena on olla mahdollisimman lähellä oikeaa laivan upotus peliä. Peli tunnistaa käyttäjän syötteen ja valinnat ja tämän avulla tulostaa kulloisenkin peli tilanteen tai asettelu tilanteen ellei automaattista asettelua ole valittu.
Ohjelma osaa myös pelata auttomaattisesti pelin läpi käyttäjän niin halutessa
Pelin lopuksi pelaaja saa tiedon pelin lopusta ja onittelun "Onneksi olkoon upotit kaikki laivat !" tämän lisäksi ohjelma tulostaa käyttäjälle "tarpeellista" tilastotietoa
Peli ei sisällä "graagista" muotoilua vaan kaikki "graafinen" olomuoto on toteutettu ASCII merkeillä.
Globaaleja muuttujia on ollut pakko käyttää, koska kaikki muut ratkaisut monimutkaistavat toteutusta huomattavasti ja globaalin muuttujan käyttö johtaa selkeään ratkaisuun.

Ohjelman ratkaisu periaatteita (Alihojelman nimi ja tehtävä):

 * nimi:MAIN
 * toiminta: Ajaa luuppi aliohjelman ja palauttaa nollan

 * nimi: luuppi
 * toiminta: Kysyy pelaajan valinnan ja pyörittää pelin silmukkaa, jos valinta on jokin muu kuin lopetus syötetään valinta valinnat aliohjelmaan ja ajetaan se.

 * nimi: kysyValinta
 * toiminta: kysyy pelaajalta syötteen ja palauttaa sen char muodossa

 * nimi: valinnat
 * toiminta: Ajaa yhden seuraavista aliohjelmista: laivanasettelu, auto_laivanasettelu , ampuminen tai auto_ampuminen.

 * nimi: laivanasettelu
 * toiminta: Alustaa tarvittavat parametrit, pyytää pelaajalta silmukassa syötteet, laivan alkupiste ja suunta.
			 Muuntaa annetut koordinaatit indexi muotoon taulukoiden käsittelyä varten.
			 Syöttää laivat_taulukkoon laivan sijainnin, toistaa silmukka kunnes viimeinen laiva on syötetty.
			 Tulostaa laivojen sijainnit käyttäjälle nähtäväksi.

 * nimi: auto_laivanasttelu
 * toiminta: Alustaa tarvittavat parametrit. Arpoo laivalle alkupisteen ja suunnan. Tutkii mahtuuko laiva kyseiseen tilaan.
			 Jos mahtuu, syöttää laivat_taulukkoon laivan sijainnin, toistaa silmukka kunnes viimeinen laiva on syötetty.
			 Tulostaa tekstin "laivat on asetettu onnistuneesti".

 * nimi: ampuminen
 * toiminta: Pyytää ampumiskoordinaatit. Muuntaa koordinaatit indeximuotoon. Jos kohta johon ammuttiin sisältää jokin laivan osa merkataan se osumaksi.
			 Laskee kuinka monta osumaa laivaan on osunut. Jos osumien lukumäärä on yhtä suuri kuin laivan pituus merkkaa laivan uponeeksi.
			 Jos kohta johon ammuttiin ei sisällä laivaa merkkaa laukauksen hudiksi. Jos osumien kokonaislukumäärä LKM_OSUMAT on 14 peli loppuu voittoon.

 * nimi: auto_ampuminen
 * toiminta: Arpoo silmukassa ampumiskohdan. Jos kohta johon ammuttiin sisältää osumat taulukossa jokin muun merkin kuin 0 arvotaan uusi ampumiskohta.
			 Jos kohta johon ammuttiin sisältää jokin laivan osa merkataan se osumaksi.
			 Laskee kuinka monta osumaa laivaan on osunut. Jos osumien lukumäärä on yhtä suuri kuin laivan pituus merkkaa laivan uponeeksi.
			 Jos kohta johon ammuttiin ei sisällä laivaa merkkaa laukauksen hudiksi. Ampumista toistetaan kunnes osumien kokonaislukumäärä LKM_OSUMAT on 14, silloin peli loppuu voittoon.

 * nimi: tilastotietojen_tulostus
 * toiminta: Laskee tehokkaimman ampumise osumisjakson. Laskee pisimmän hutien jakson. Tulostaa pelaajalle tilastotiedot.

 * nimi: valikon_tulostus
 * toiminta:Tulostetaan alkuvalikko pelaajalle

 * nimi: laivojen_tulostus
 * toiminta: Tulostaa laivat_taulukon kaikki alkiot (laivojen sijainnit)

 * nimi: Taulukoiden alustus
 * toiminta: Alustaa laivat taulukon ja osumat taulukon.

 * nimi: T_reset
 * toiminta: Alustaa tilastotiedot.

 Kun tarkaillaan ohjelmarakennetta voidaan huomata, että suurin osa aliohjelmista ei palauta arvoja toisille aliohjelmille, koska sille ei ole syytä. Aliohjelmat ovat siitä syystä void alkuisia.
 On huomattavaa myös, että aliohjelmat on pyritty ohjelmoimaan mahdollisimman lyhyesti ja tiiviisti, jotta niiden suoritus olisi optimoitua.
 Valitettavasti kuten jo aijemmin todettiin emme pystyneet välttämään globaalien muuttujien käyttämistä, koska muut ratkaisut olisivat monimutkaistaneet toteutusta huomattavasti ja globaalien muuttujien käyttö johti selkeään ratkaisuun.

 Aliohjelmat on pääasiassa ratkaistu for/while silmukoilla tai switch rakenteella joilla pystyttiin jatkamaan suoritusta kunnes ehto täyttyi. Switch rakennetta hyödynnettiin kun halusimme muuntaa kirjain koordinaatin vastaavaksi indexiarvoksi.
 Laivan automaattisessa asettelussa myös varmistimme sen, että laivat eivät mene rajojen yli. Samaa tarkistusta ei kuitenkaan ole laitettu käsin asetteluun, koska oletetaan että syötteet ovat oikein eikä tälläista tilannetta synny.




Päiväys: 10.4.2013

*/



#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <windows.h>
using namespace std;

// aliohjelmat
void luuppi ();
void valikon_tulostus();
char kysyValinta ();
void valinnat (char);
void laivanasettelu ();
void auto_laivanasettelu ();
void osumien_tulostus ();
void laivojen_tulostus ();
void taulukoiden_alustus ();
void tilastotietojen_tulostus ();
void T_reset ();

// laivan ampuminen syöttäen koordinaatit manuaalisesti
void ampuminen (bool &, int &);

// laivan ampuminen automaattisesti ilman syötteiden antoa
void auto_ampuminen (bool &, int &);

// globaali laivat-taulukko johon tallennetaan laivojen sijainnit
const int RIVIT = 7;
const int KOLUMNIT = 7;
int laivat [RIVIT][KOLUMNIT] = {0};

// globaali osumataulukko johon talletetaan osumat, hudit ja uponneet laivat
char osumat [RIVIT][KOLUMNIT];

// globaali laivojen idexitaulukko [mikä laiva], [mikä osa laivaa], [indexit]
int laivojen_indexit[6][5][2] = {0};

//globaalit tilastotieto-muuttujat
int T_KAIKKI_AMMUNNAT = 0;
int T_ALKU_HUDIT = 0;
int T_laivojen_upottavat_ammunnat[6] = {0};
int T_laivojen_ensimmaiset_osumat[6] = {0};
int T_uppoamisjarjestys[4] = {0};
int T_kaikki_osumat_ja_hudit[50] = {0};



int main()
{
	/*--------------------------------------------------
 *
 * nimi:MAIN
 * toiminta: Ajaa luuppi aliohjelman ja palauttaa nollan
 * parametri(t): -
 * paluuarvo(t): 0
 *
 *--------------------------------------------------*/

	luuppi();

	system ("PAUSE");
	return 0;
}

void luuppi()
{
	/*--------------------------------------------------
 *
 * nimi: luuppi
 * toiminta: Kysyy pelaajan valinnan ja pyörittää pelin silmukkaa. 
			 Jos valinta on jokin muu kuin lopetus syötetään valinta valinnat aliohjelmaan ja ajetaan se.
 * parametri(t): char valinta
 * paluuarvo(t): -
 *
 *--------------------------------------------------*/

	char valinta;

	srand(time(0));

	while (true)
	{
		valikon_tulostus();
	
		do
		{
		valinta = kysyValinta();
		if (valinta != 'l' && valinta != 'L' && valinta != '1' && valinta != '2' && valinta != '3' && valinta != '4')
		{
			cout << "Valitse jokin annetuista vaihtoehdoista!" << endl;
			cout << "Valintasi: ";
		}
		}while (valinta != 'l' && valinta != 'L' && valinta != '1' && valinta != '2' && valinta != '3' && valinta != '4');

		if (valinta == 'l' || valinta == 'L')
		{
			cout << endl << "Kiitos ja nakemiin."<< endl << endl;
			return;
		}
		else
			valinnat (valinta);	
	}		
}

char kysyValinta ()
{
/*--------------------------------------------------
 *
 * nimi: kysyValinta
 * toiminta: kysyy pelaajalta syötteen ja palauttaa sen char muodossa
 * parametri(t): char valinta[]
 * paluuarvo(t): char
 *
 *--------------------------------------------------*/

	char valinta[5];
	cin.getline (valinta,5);
	return valinta[0];
}

void valinnat ( char valinta )
{
/*--------------------------------------------------
 *
 * nimi: valinnat
 * toiminta: Ajaa yhden seuraavista aliohjelmista: laivanasettelu, auto_laivanasettelu , ampuminen tai auto_ampuminen.
 * parametri(t): static int LKM_OSUMAT, static bool laivat_asetettu
 * paluuarvo(t): -
 *
 *--------------------------------------------------*/
	static int LKM_OSUMAT = 0;
	static bool laivat_asetettu = false;

	if (valinta == '1')
	{
		laivanasettelu ();	

		T_reset (); // resetoi tilastotieto_muuttujat
		LKM_OSUMAT = 0;
		laivat_asetettu = true;
	}

	else if (valinta == '2')
	{
		if (laivat_asetettu)
		{ 
			ampuminen (laivat_asetettu, LKM_OSUMAT);
		}
		else
			cout << endl << "Aseta laivat ennen kuin pelaat!" << endl;
	}

	else if (valinta == '3')
	{
		auto_laivanasettelu ();

		T_reset (); // resetoi tilastotieto_muuttujat
		LKM_OSUMAT = 0;
		laivat_asetettu = true;
	}

	else if ( valinta == '4')
	{
		if (laivat_asetettu)
		{ 
			auto_ampuminen (laivat_asetettu, LKM_OSUMAT);
		}
		else
			cout << endl << "Aseta laivat ennen kuin pelaat!" << endl;
	}
}

void laivanasettelu ()
{
/*--------------------------------------------------
 *
 * nimi: laivanasettelu
 * toiminta: Alustaa tarvittavat parametrit, pyytää pelaajalta silmukassa syötteet, laivan alkupiste ja suunta.
			 Muuntaa annetut koordinaatit indexi muotoon taulukoiden käsittelyä varten.
			 Syöttää laivat_taulukkoon laivan sijainnin, toistaa silmukka kunnes viimeinen laiva on syötetty.
			 Tulostaa laivojen sijainnit käyttäjälle nähtäväksi.
 * parametri(t): int laivan_pituus, char koodinaatti[], char suunta[], int rivi_indexi, int kolumni_indexi
 * paluuarvo(t): -
 *
 *--------------------------------------------------*/
	int laivan_pituus = 5;
	char koordinaatti[5];
	char suunta[5];
	int rivi_indexi = 0;
	int kolumni_indexi = 0;

	taulukoiden_alustus ();

	cout << endl << "Valitsit laivan asettelun." << endl;

	while (laivan_pituus > 1)
	{
		laivojen_tulostus ();

		if (laivan_pituus == 5)
		{
			cout << endl << endl << "Anna viiden pituisen laivan alkupiste: "; 
		}
		else if (laivan_pituus == 4)
		{
			cout << endl << endl << "Anna neljan pituisen laivan alkupiste: "; 
		}
		else if (laivan_pituus == 3)
		{
			cout << endl << endl << "Anna kolmen pituisen laivan alkupiste: "; 
		}
		else if (laivan_pituus == 2)
		{
			cout << endl << endl << "Anna kahden pituisen laivan alkupiste: "; 
		}

		cin.getline (koordinaatti,5);
		cout << "Anna suunta (p(ohjoinen)/i(ta)/e(tela)/l(ansi)): ";
		cin.getline (suunta,5);

		// Annettu koordinaatin kirjain muutetaan isokirjaimeksi
		koordinaatti[0] = char(toupper(koordinaatti[0]));

		switch (koordinaatti[0])
		{
			case 'A':
				rivi_indexi = 0;
				break;
			case 'B':
				rivi_indexi = 1;
				break;
			case 'C':
				rivi_indexi = 2;
				break;
			case 'D':
				rivi_indexi = 3;
				break;
			case 'E':
				rivi_indexi = 4;
				break;
			case 'F':
				rivi_indexi = 5;
				break;
			case 'G':
				rivi_indexi = 6;
				break;
		}
		switch (koordinaatti[1])
		{
			case '1':
				kolumni_indexi = 0;
				break;
			case '2':
				kolumni_indexi = 1;
				break;
			case '3':
				kolumni_indexi = 2;
				break;
			case '4':
				kolumni_indexi = 3;
				break;
			case '5':
				kolumni_indexi = 4;
				break;
			case '6':
				kolumni_indexi = 5;
				break;
			case '7':
				kolumni_indexi = 6;
				break;
		}

		for (int i = 0; i < laivan_pituus; i++)
		{
			laivat[rivi_indexi][kolumni_indexi] = laivan_pituus;

			laivojen_indexit[laivan_pituus][i][0] = rivi_indexi;
			laivojen_indexit[laivan_pituus][i][1] = kolumni_indexi;

			if (suunta[0] == 'i' || suunta[0] == 'I')
				kolumni_indexi++;
			else if (suunta[0] == 'l' || suunta[0] == 'L')
				kolumni_indexi--;
			else if (suunta[0] == 'p' || suunta[0] == 'P')
				rivi_indexi--;
			else if (suunta[0] == 'e' || suunta[0] == 'E')
				rivi_indexi++;
		}

		laivan_pituus--; 
	}

	laivojen_tulostus ();
}

void auto_laivanasettelu ()
{
/*--------------------------------------------------
 *
 * nimi: auto_laivanasttelu
 * toiminta: Alustaa tarvittavat parametrit. Arpoo laivalle alkupisteen ja suunnan. Tutkii mahtuuko laiva kyseiseen tilaan.
			 Jos mahtuu, syöttää laivat_taulukkoon laivan sijainnin, toistaa silmukka kunnes viimeinen laiva on syötetty.
			 Tulostaa tekstin "laivat on asetettu onnistuneesti".
 * parametri(t): int laivan_pituus, char suunta[], char c_suunta, int rivi_indexi, int kolumni_indexi, bool portinvartija, bool vapaa_paikka
 * paluuarvo(t): -
 *
 *--------------------------------------------------*/
	int laivan_pituus = 5;
	char suunta[5] = "ilpe";
	char c_suunta;
	int rivi_indexi = 0;
	int kolumni_indexi = 0;

	taulukoiden_alustus ();

	while (laivan_pituus > 1)
	{
		bool portinvartija = false;
		bool vapaa_paikka = true;

		rivi_indexi = rand() % 7;
		kolumni_indexi = rand() % 7;
		c_suunta = suunta[rand() % 4];

		if (c_suunta == 'i')
		{
			if ( kolumni_indexi + laivan_pituus < 7)
			{
				for (int i = 0; i < laivan_pituus; i++)
				{
					if (laivat[rivi_indexi][kolumni_indexi + i] != 0)
					{
						vapaa_paikka = false;
					}
				}

				if (vapaa_paikka)
				{
					portinvartija = true;
				}
			}
		}
		else if (c_suunta == 'l')
		{
			if ( kolumni_indexi - laivan_pituus >= 0)
			{
				for (int i = 0; i < laivan_pituus; i++)
				{
					if (laivat[rivi_indexi][kolumni_indexi - i] != 0)
					{
						vapaa_paikka = false;
					}
				}

				if (vapaa_paikka)
				{
					portinvartija = true;
				}
			}
		}
		else if (c_suunta == 'e')
		{
			if ( rivi_indexi + laivan_pituus < 7)
			{
				for (int i = 0; i < laivan_pituus; i++)
				{
					if (laivat[rivi_indexi + i][kolumni_indexi] != 0)
					{
						vapaa_paikka = false;
					}
				}

				if (vapaa_paikka)
				{
					portinvartija = true;
				}
			}
		}
		else if (c_suunta == 'p')
		{
			if ( rivi_indexi - laivan_pituus >= 0)
			{
				for (int i = 0; i < laivan_pituus; i++)
				{
					if (laivat[rivi_indexi - i][kolumni_indexi] != 0)
					{
						vapaa_paikka = false;
					}
				}

				if (vapaa_paikka)
				{
					portinvartija = true;
				}
			}
		}

		if (portinvartija)
		{
			for (int i = 0; i < laivan_pituus; i++)
			{

				laivat[rivi_indexi][kolumni_indexi] = laivan_pituus;

				laivojen_indexit[laivan_pituus][i][0] = rivi_indexi;
				laivojen_indexit[laivan_pituus][i][1] = kolumni_indexi;

				if (c_suunta == 'i')
					kolumni_indexi++;
				else if (c_suunta == 'l')
					kolumni_indexi--;
				else if (c_suunta == 'p')
					rivi_indexi--;
				else if (c_suunta == 'e')
					rivi_indexi++;
			} 

			laivan_pituus--;
		}
	}

	cout << endl << "Laivat asetettu onnistuneesti." << endl;
}

void ampuminen (bool &laivat_asetettu, int &LKM_OSUMAT)
{
/*--------------------------------------------------
 *
 * nimi: ampuminen
 * toiminta: Pyytää ampumiskoordinaatit. Muuntaa koordinaatit indeximuotoon. Jos kohta johon ammuttiin sisältää jokin laivan osa merkataan se osumaksi.
			 Laskee kuinka monta osumaa laivaan on osunut. Jos osumien lukumäärä on yhtä suuri kuin laivan pituus merkkaa laivan uponeeksi.
			 Jos kohta johon ammuttiin ei sisällä laivaa merkkaa laukauksen hudiksi. Jos osumien kokonaislukumäärä LKM_OSUMAT on 14 peli loppuu voittoon.
 * parametri(t): char koordinaatti[], int rivi_indexi, int kolumni_indexi, int osumien_lkm, int asciiKeno, int LKM_OSUMAT, bool laivat_asetettu,
				 int T_KAIKKI_AMMUNNAT, int T_ALKU_HUDIT, int T_laivojen_upottavat_ammunnat[], int T_laivojen_ensimmaiset_osumat[], int T_uppoamisjarjestys[], int T_kaikki_osumat_ja_hudit[]
 * paluuarvo(t): -
 *
 *--------------------------------------------------*/
	char koordinaatti[5];
	int rivi_indexi = 0;
	int kolumni_indexi = 0;
	int osumien_lkm = 0;
	int asciiKeno = 92;

	while(true)
	{
		osumien_lkm = 0;

		cout << endl << "Pelitilanne on seuraava:" << endl << endl;
		osumien_tulostus();

		cout << endl << "Anna ampumiskoordinaatti: ";
		cin.getline (koordinaatti,5);

		if ( koordinaatti[0] == asciiKeno && koordinaatti[1] == '@' )
		{
			cout << endl << "Laivat sijaitsevat seuraavissa paikoissa:" << endl;
			laivojen_tulostus ();
		}

		else
		{
			// Annettu koordinaatin kirjain muutetaan isokirjaimeksi
			koordinaatti[0] = char(toupper(koordinaatti[0]));

				switch (koordinaatti[0])
			{
				case 'A':
					rivi_indexi = 0;
					break;
				case 'B':
					rivi_indexi = 1;
					break;
				case 'C':
					rivi_indexi = 2;
					break;
				case 'D':
					rivi_indexi = 3;
					break;
				case 'E':
					rivi_indexi = 4;
					break;
				case 'F':
					rivi_indexi = 5;
					break;
				case 'G':
					rivi_indexi = 6;
					break;
				case 'P':
					return;
			}
			switch (koordinaatti[1])
			{
				case '1':
					kolumni_indexi = 0;
					break;
				case '2':
					kolumni_indexi = 1;
					break;
				case '3':
					kolumni_indexi = 2;
					break;
				case '4':
					kolumni_indexi = 3;
					break;
				case '5':
					kolumni_indexi = 4;
					break;
				case '6':
					kolumni_indexi = 5;
					break;
				case '7':
					kolumni_indexi = 6;
					break;
			}

			T_KAIKKI_AMMUNNAT++;

			// Jos kohta johon ammuttiin sisältää jokin laivan osa merkataan se osumaksi.
			if ( laivat[rivi_indexi][kolumni_indexi] != 0) 
			{
				// Laitetaan osuman merkiksi ykkönen taulukkoon T_kaikki_osumat_ja_hudit kohtaan T_KAIKKI_AMMUNNAT-1.
				T_kaikki_osumat_ja_hudit[T_KAIKKI_AMMUNNAT-1] = 1;

				// Otetaan laivan pituus laivat taulukosta osuma koordinaateista.
				cout << endl << endl << "Laukaus kohtaan " << koordinaatti[0] << koordinaatti[1] << " osui laivaan.";
				int laivan_pituus = laivat[rivi_indexi][kolumni_indexi];

				// Laitetaan osumat taulukkoon tähti ammuttuun kohtaan osuman merkiksi.
				osumat[rivi_indexi][kolumni_indexi]  = '*';

				// Laitetaan kaikkien tähän mennessä ammuttujen laukausten lukumäärä taulukkoon T_laivojen_ensimmaiset_osumat kun laivaan osuu ensimmäistä kertaa.
				if (T_laivojen_ensimmaiset_osumat[laivan_pituus] == 0)
				{
					T_laivojen_ensimmaiset_osumat[laivan_pituus] = T_KAIKKI_AMMUNNAT;// miinustetaan yksi koska halutaan poissulkea itse osuma.
				}

				LKM_OSUMAT++; 
			

				// Lasketaan kuinka monta osumaa laivaan on osunut.
				for (int i = 0; i < laivan_pituus; i++)
				{
					rivi_indexi = laivojen_indexit[laivan_pituus][i][0];
					kolumni_indexi = laivojen_indexit[laivan_pituus][i][1];

					if (osumat[rivi_indexi][kolumni_indexi] == '*')
					{
						osumien_lkm++;
					}
					else
						break;
				}


				// Jos osumien lukumäärä on yhtä suuri kuin laivan pituus, laiva uppoaa.
				if (osumien_lkm == laivan_pituus)
				{
					cout << endl << "Laukaus upotti laivan.";

					// Lisätään uponneen laivan pituus taulukkoon josta selviää laivojen uppoamisjärjestys.
					for (int i = 0; true; i++)
					{
						if (T_uppoamisjarjestys[i] == 0)
						{
							T_uppoamisjarjestys[i] = laivan_pituus;
							break;
						}
					}

					// Lisätään taulukkoon T_laivojen_upottavat_ammunnat kaikkiaan ammuttujen laukausten lukumäärä alusta asti kyseiselle laivalle.
					T_laivojen_upottavat_ammunnat[laivan_pituus] = T_KAIKKI_AMMUNNAT;

					for (int i = 0; i < laivan_pituus; i++)
					{
						osumat[laivojen_indexit[laivan_pituus][i][0]][laivojen_indexit[laivan_pituus][i][1]] = '#';
					}
				}
	
			}
			else
			{		
				cout << endl << endl << "Laukaus kohtaan " << koordinaatti[0] << koordinaatti[1] << " ei osunut.";
				osumat [rivi_indexi][kolumni_indexi]  = 'X';

				if (LKM_OSUMAT == 0)
					T_ALKU_HUDIT++;
			}

			if (LKM_OSUMAT == 14)
			{
				osumien_tulostus();
				cout << endl << "ONNEKSI OLKOON UPOTIT KAIKKI LAIVAT!!!" << endl << endl;
				tilastotietojen_tulostus();

				laivat_asetettu = false;
				return;
			}
		}
	}
}

void auto_ampuminen (bool &laivat_asetettu, int &LKM_OSUMAT)
{
					/*--------------------------------------------------
 *
 * nimi: auto_ampuminen
 * toiminta: Arpoo silmukassa ampumiskohdan. Jos kohta johon ammuttiin sisältää osumat taulukossa jokin muun merkin kuin 0 arvotaan uusi ampumiskohta.
			 Jos kohta johon ammuttiin sisältää jokin laivan osa merkataan se osumaksi.
			 Laskee kuinka monta osumaa laivaan on osunut. Jos osumien lukumäärä on yhtä suuri kuin laivan pituus merkkaa laivan uponeeksi.
			 Jos kohta johon ammuttiin ei sisällä laivaa merkkaa laukauksen hudiksi. Ampumista toistetaan kunnes osumien kokonaislukumäärä LKM_OSUMAT on 14, silloin peli loppuu voittoon.
 * parametri(t): char koordinaatti[], int rivi_indexi, int kolumni_indexi, int osumien_lkm, int asciiKeno, int LKM_OSUMAT, bool laivat_asetettu,
				 int T_KAIKKI_AMMUNNAT, int T_ALKU_HUDIT, int T_laivojen_upottavat_ammunnat[], int T_laivojen_ensimmaiset_osumat[], int T_uppoamisjarjestys[], int T_kaikki_osumat_ja_hudit[]
 * paluuarvo(t): -
 *
 *--------------------------------------------------*/
	char koordinaatti[5];
	int rivi_indexi = 0;
	int kolumni_indexi = 0;
	int osumien_lkm = 0;
	int asciiKeno = 92;

	cout << "Valitsit automaattisen ampumisen !" << endl;

	while(true)
	{
		osumien_lkm = 0;

		rivi_indexi = rand() % 7;
		kolumni_indexi = rand() % 7;
		
	
		if (osumat[rivi_indexi][kolumni_indexi]  != '*' && osumat[rivi_indexi][kolumni_indexi]  != '#' && osumat[rivi_indexi][kolumni_indexi]  != 'X')
		{
			T_KAIKKI_AMMUNNAT++;

			osumien_tulostus ();
			Sleep (10); //odottaa 1.5s ennen kuin asettaa ampumis tuloksen

			// Jos kohta johon ammuttiin sisältää jokin laivan osa merkataan se osumaksi.
			if ( laivat[rivi_indexi][kolumni_indexi] != 0) 
			{
				// Laitetaan osuman merkiksi ykkönen taulukkoon T_kaikki_osumat_ja_hudit kohtaan T_KAIKKI_AMMUNNAT-1.
				T_kaikki_osumat_ja_hudit[T_KAIKKI_AMMUNNAT-1] = 1;

				// Otetaan laivan pituus laivat taulukosta osuma koordinaateista.
				int laivan_pituus = laivat[rivi_indexi][kolumni_indexi];

				// Laitetaan osumat taulukkoon tähti ammuttuun kohtaan osuman merkiksi.
				osumat[rivi_indexi][kolumni_indexi]  = '*';

				// Laitetaan kaikkien tähän mennessä ammuttujen laukausten lukumäärä taulukkoon T_laivojen_ensimmaiset_osumat kun laivaan osuu ensimmäistä kertaa.
				if (T_laivojen_ensimmaiset_osumat[laivan_pituus] == 0)
				{
					T_laivojen_ensimmaiset_osumat[laivan_pituus] = T_KAIKKI_AMMUNNAT;// miinustetaan yksi koska halutaan poissulkea itse osuma.
				}

				LKM_OSUMAT++; 
			

				// Lasketaan kuinka monta osumaa laivaan on osunut.
				for (int i = 0; i < laivan_pituus; i++)
				{
					rivi_indexi = laivojen_indexit[laivan_pituus][i][0];
					kolumni_indexi = laivojen_indexit[laivan_pituus][i][1];

					if (osumat[rivi_indexi][kolumni_indexi] == '*')
					{
						osumien_lkm++;
					}
					else
						break;
				}


				// Jos osumien lukumäärä on yhtä suuri kuin laivan pituus, laiva uppoaa.
				if (osumien_lkm == laivan_pituus)
				{
					cout << endl << "Laukaus upotti laivan.";

					// Lisätään uponneen laivan pituus taulukkoon josta selviää laivojen uppoamisjärjestys.
					for (int i = 0; true; i++)
					{
						if (T_uppoamisjarjestys[i] == 0)
						{
							T_uppoamisjarjestys[i] = laivan_pituus;
							break;
						}
					}

					// Lisätään taulukkoon T_laivojen_upottavat_ammunnat kaikkiaan ammuttujen laukausten lukumäärä alusta asti kyseiselle laivalle.
					T_laivojen_upottavat_ammunnat[laivan_pituus] = T_KAIKKI_AMMUNNAT;

					for (int i = 0; i < laivan_pituus; i++)
					{
						osumat[laivojen_indexit[laivan_pituus][i][0]][laivojen_indexit[laivan_pituus][i][1]] = '#';
					}
				}
	
			}
			else
			{
				osumat [rivi_indexi][kolumni_indexi]  = 'X';
				
				if (LKM_OSUMAT == 0)
					T_ALKU_HUDIT++;
			}

			if (LKM_OSUMAT == 14)
			{
				osumien_tulostus();
				cout << endl << "ONNEKSI OLKOON UPOTIT KAIKKI LAIVAT!!!" << endl << endl;
				tilastotietojen_tulostus();

				laivat_asetettu = false;
				return;
			}
		}
	}
}

void tilastotietojen_tulostus ()
{
/*--------------------------------------------------
 *
 * nimi: tilastotietojen_tulostus
 * toiminta: Laskee tehokkaimman ampumise osumisjakson. Laskee pisimmän hutien jakson. Tulostaa pelaajalle tilastotiedot.
 * parametri(t): float tehokkain, int laivan_pituus, int jakso, int pisin_jakso, int aloitus_kohta, int aloitus_kohta_max,
 * paluuarvo(t): -
 *
 *--------------------------------------------------*/
	// Lasketaan tehokkain ampumisen osumisjakso
	float tehokkain = 1000.00;
	int laivan_pituus;

	for (int i = 5; i >= 2; i--)
	{
		if ((T_laivojen_upottavat_ammunnat[i] - (T_laivojen_ensimmaiset_osumat[i]-1)) / i < tehokkain)
		{
			tehokkain = (float(T_laivojen_upottavat_ammunnat[i]) - (float(T_laivojen_ensimmaiset_osumat[i])-1.0)) / float(i);
			laivan_pituus = i;
		}

	}

	// Lasketaan pisin hutien jakso
	int jakso = 0;
	int pisin_jakso = 0;
	int aloitus_kohta;
	int aloitus_kohta_max;
	
	for (int i = 0; i < T_KAIKKI_AMMUNNAT; i++)
	{
		if (T_kaikki_osumat_ja_hudit[i] == 0)
		{		
			if (jakso == 0)
			{
				aloitus_kohta = i+1;
			}
			jakso++;
			

			if (jakso > pisin_jakso)
			{
				pisin_jakso = jakso;
				aloitus_kohta_max = aloitus_kohta;
			}
		}

		else
		{
			jakso = 0;
		}
	}


	// Tulostetaan tilastotiedot.
	cout << endl << "------TILASTOTIETOJA------" << endl << endl
		<< "Pelissa ammuttujen laukausten lukumaara:\t " << T_KAIKKI_AMMUNNAT << endl
		<< "Pelin alussa ammuttujen hutien lukumaara:\t " << T_ALKU_HUDIT << endl << endl
		<< "Laivan (5) upottamiseen tarvitut laukaukset alusta lukien:\t " << T_laivojen_upottavat_ammunnat[5] << endl
		<< "Laivan (4) upottamiseen tarvitut laukaukset alusta lukien:\t " << T_laivojen_upottavat_ammunnat[4] << endl
		<< "Laivan (3) upottamiseen tarvitut laukaukset alusta lukien:\t " << T_laivojen_upottavat_ammunnat[3] << endl
		<< "Laivan (2) upottamiseen tarvitut laukaukset alusta lukien:\t " << T_laivojen_upottavat_ammunnat[2] << endl << endl
		<< "Laivan (5) upottamiseen tarvitut laukaukset:\t " << T_laivojen_upottavat_ammunnat[5] - (T_laivojen_ensimmaiset_osumat[5]-1) << endl
		<< "Laivan (4) upottamiseen tarvitut laukaukset:\t " << T_laivojen_upottavat_ammunnat[4] - (T_laivojen_ensimmaiset_osumat[4]-1) << endl
		<< "Laivan (3) upottamiseen tarvitut laukaukset:\t " << T_laivojen_upottavat_ammunnat[3] - (T_laivojen_ensimmaiset_osumat[3]-1) << endl
		<< "Laivan (2) upottamiseen tarvitut laukaukset:\t " << T_laivojen_upottavat_ammunnat[2] - (T_laivojen_ensimmaiset_osumat[2]-1) << endl << endl
		<< "Ensimmaiseksi upposi \t(" << T_uppoamisjarjestys[0] << ") pituinen laiva." << endl
		<< "Toiseksi upposi \t(" << T_uppoamisjarjestys[1] << ") pituinen laiva." << endl
		<< "Kolmanneksi upposi \t(" << T_uppoamisjarjestys[2] << ") pituinen laiva." << endl
		<< "Neljanneksi upposi \t(" << T_uppoamisjarjestys[3] << ") pituinen laiva." << endl << endl
		<< "Tehokkain ampumisten osumisjakso oli laukaukset " <<  T_laivojen_ensimmaiset_osumat[laivan_pituus] << ". - "
		<< T_laivojen_upottavat_ammunnat[laivan_pituus] << "." << endl << "joilla upotettiin " << laivan_pituus << " pituinen laiva." << endl << endl
		<< "Pisin ohilaukausjakso oli " << aloitus_kohta_max << ". - " << aloitus_kohta_max + pisin_jakso - 1 << ".";
}

void valikon_tulostus()
{
/*--------------------------------------------------
 *
 * nimi: valikon_tulostus
 * toiminta:Tulostetaan alkuvalikko pelaajalle
 * parametri(t):-
 * paluuarvo(t): -
 *
 *--------------------------------------------------*/
	cout << endl << endl << "LAIVANUPOTUS PELI" << endl << "=================" << endl << endl;
	cout << "Valikko" << endl;
	cout << "1) Syota laivat" << endl;
	cout << "2) Pelaa" << endl;
	cout << "3) Arvo laivojen sijainnit" << endl;
	cout << "4) Automaattinen laivojen ampuminen" << endl;
	cout << "L) Lopeta" << endl << endl;
	cout << "Valinta: ";
}

void osumien_tulostus ()
{
/*--------------------------------------------------
 *
 * nimi: osumien_tulostus
 * toiminta: tulostaa osumat_taulokon kaikki merkit (osumat, hudit ja upotukset)
 * parametri(t):-
 * paluuarvo(t): -
 *
 *--------------------------------------------------*/
	cout << endl << "    1 2 3 4 5 6 7" << endl;
	cout << "  -----------------" << endl;
	cout << "A |" << " "; for (int i=0; i<7; i++){cout << osumat[0][i] << " ";} cout << "| A" << endl;
	cout << "B |" << " "; for (int i=0; i<7; i++){cout << osumat[1][i] << " ";} cout << "| B" << endl;
	cout << "C |" << " "; for (int i=0; i<7; i++){cout << osumat[2][i] << " ";} cout << "| C" << endl;
	cout << "D |" << " "; for (int i=0; i<7; i++){cout << osumat[3][i] << " ";} cout << "| D" << endl;
	cout << "E |" << " "; for (int i=0; i<7; i++){cout << osumat[4][i] << " ";} cout << "| E" << endl;
	cout << "F |" << " "; for (int i=0; i<7; i++){cout << osumat[5][i] << " ";} cout << "| F" << endl;
	cout << "G |" << " "; for (int i=0; i<7; i++){cout << osumat[6][i] << " ";} cout << "| G" << endl;
	cout << "  -----------------"  << endl;
	cout <<    "    1 2 3 4 5 6 7" << endl;
}

void laivojen_tulostus ()
{
/*--------------------------------------------------
 *
 * nimi: laivojen_tulostus
 * toiminta: Tulostaa laivat_taulukon kaikki alkiot (laivojen sijainnit)
 * parametri(t):-
 * paluuarvo(t): -
 *
 *--------------------------------------------------*/	
	cout << endl << "    1 2 3 4 5 6 7" << endl;
	cout << "  -----------------" << endl;
	cout << "A |" << " "; for (int i=0; i<7; i++){cout << laivat[0][i] << " ";} cout << "| A" << endl;
	cout << "B |" << " "; for (int i=0; i<7; i++){cout << laivat[1][i] << " ";} cout << "| B" << endl;
	cout << "C |" << " "; for (int i=0; i<7; i++){cout << laivat[2][i] << " ";} cout << "| C" << endl;
	cout << "D |" << " "; for (int i=0; i<7; i++){cout << laivat[3][i] << " ";} cout << "| D" << endl;
	cout << "E |" << " "; for (int i=0; i<7; i++){cout << laivat[4][i] << " ";} cout << "| E" << endl;
	cout << "F |" << " "; for (int i=0; i<7; i++){cout << laivat[5][i] << " ";} cout << "| F" << endl;
	cout << "G |" << " "; for (int i=0; i<7; i++){cout << laivat[6][i] << " ";} cout << "| G" << endl;
	cout << "  -----------------"  << endl;
	cout << "    1 2 3 4 5 6 7" << endl;
}

void taulukoiden_alustus ()
{
/*--------------------------------------------------
 *
 * nimi: Taulukoiden alustus
 * toiminta: Alustaa laivat taulukon ja osumat taulukon.
 * parametri(t): int RIVIT, int KOLUMNIT, int laivat[], char osumat[]
 * paluuarvo(t): -
 *
 *--------------------------------------------------*/	
	for (int i = 0; i < RIVIT; i++)
	{
		for (int j = 0; j < KOLUMNIT; j++){ laivat[i][j] = 0;}	
	}

	for (int i = 0; i < RIVIT; i++)
	{
		for (int j = 0; j < KOLUMNIT; j++){ osumat[i][j] = ' ';}	
	}
}

void T_reset ()
{
/*--------------------------------------------------
 *
 * nimi: T_reset
 * toiminta: Alustaa tilastotiedot.
 * parametri(t): int T_laivojen_upottavat_ammunat[], int T_laivojen_ensimmaiset_osumat[], int T_upottamisjarjestys[], int T_KAIKKI_AMMUNNAT, int T_ALKU_HUDIT
 * paluuarvo(t): -
 *
 *--------------------------------------------------*/	
	for (int i = 0; i < 6; i++)
	{
		T_laivojen_upottavat_ammunnat[i] = 0;
		T_laivojen_ensimmaiset_osumat[i] = 0;
	}
	for (int i = 0; i < 4; i++)
	{
		T_uppoamisjarjestys[i] = 0;	
	}
	for (int i = 0; i < 50; i++)
	{
		T_kaikki_osumat_ja_hudit[i] = 0;
	}
	T_KAIKKI_AMMUNNAT = 0;
	T_ALKU_HUDIT = 0;
}
