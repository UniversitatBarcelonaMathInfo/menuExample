// Variables
byte ddL, ddS; // define distance long and short
int dL, dF, dR; // Distance left, forward and right

void (*MyAlgotithm) ();
void (*pared[8]) (); // 8 porque 0 - 7, son 8 elementos

// Declarando funciones
void NonParet ();
void OnlyLeft ();
void OnlyForward ();
void ParedLeftForwad ();
void OnlyRight ();
void ParedLeftRight ();
void ParedForwardRight ();
void Pared ();
void Forward ();


void initAlgotimo () { MyAlgotithm = empty; } // Epic solution for ever
void algotitmo ()
{	MyAlgotithm (); }


void Wait ()
{
	aux = detectObject ();
	if ( aux )
		MyAlgotithm = pared [ aux ];
}
void initParet ()
{
	byte aux;
// Llamada a detector, para definir a que distancia da positivo el sensor.
	defineDetect ( ddL );

	pared[0] = NonParet;
	pared[1] = OnlyLeft;
	pared[2] = OnlyForward;
	pared[3] = ParedLeftForwad;
	pared[4] = OnlyRight;
	pared[5] = ParedLeftRight;
	pared[6] = ParedForwardRight;
	pared[7] = Pared;

// Inicialitzem amb valors no valids, per a evitar confucions
	dL = dF = dR = -1;
	aux = detectObject ();
	if ( aux )
		MyAlgotithm = pared [ aux ];
	else
	{
		robotForward ();
		MyAlgotithm = Wait;
	}

}
void NonParet ()
{
	if ( dL >= 0 )
	{
		dF = dR = -1;
		dL = 0;
		robotTurnLeftSearchWall ();
	} else if ( dR >= 0 )
	{
		dL = dF = -1;
		dR = 0;
		robotTurnRightSearchWall ();
	} else
	{
		dL = dR = -1;
		dF = 0;
		robotForward ();
	}
	MyAlgotithm = Wait;
}
void OnlyLeft ();
void OnlyForward ();
void ParedLeftForwad ();
void OnlyRight ();
void ParedLeftRight ();
void ParedForwardRight ();
void Pared ();
