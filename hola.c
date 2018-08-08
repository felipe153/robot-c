#pragma config(Sensor, S1, colorSensor, sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
TLegoColors estadocolor;
//#########################################################################################################
/*#########################################################################################################
Nombre variable: Sensor asociado
S1: Sensor de color
S2: Sensor giroscopio
S3: Sensor de color
leftMotor: Motor izquierdo
rightMotor: Motor derecho
armMotor: motor en la parte trasera del robot
##########################################################################################################*/
//########################################################################################################
bool color_Green(){//Funcion, la cual retornara un valor verdadero si el sensor de color conectado en el espacio 1, detecta verde
	if(getColorName(S1)== colorGreen){
		return true;
	}
	else{
		return false;
	}
}

bool color_Black(){//Funcion, la cual retornara un valor verdadero si el sensor de color conectado en el espacio 1, detecta negro
	if(getColorName(S1)== colorBlack){
		return true;
	}
	else{
		return false;
	}
}
 void brazoAbajo(){ // funcion para bajar el  brazo
setMotorTarget(armMotor,-130,30);
}
 void brazoArriba(){// funcion para subir el brazo
setMotorTarget(armMotor,0,30);
}
bool color_Red(){//Funcion, la cual retornara un valor verdadero si el sensor de color conectado en el espacio 1, detecta rojo
	if(getColorName(S1)== colorRed){
		return true;
	}
	else{
		return false;
	}
}

bool color_Blue(){//Funcion, la cual retornara un valor verdadero si el sensor de color conectado en el espacio 1, detecta azul
	if(getColorName(S1)== colorBlue){
		return true;
	}
	else{
		return false;
	}
}
bool color_white(){//Funcion, la cual retornara un valor verdadero si el sensor de color conectado en el espacio 1, detecta blanco
	if(getColorName(S1)== colorWhite){
		return true;
	}
	else{
		return false;
	}
}

void avanzar(int power_motor){//Funcion para avanzar acorde la potencia dada dentro del main
	motor[rightMotor] = power_motor;
  motor[leftMotor]  = power_motor;
}

void retroceder(int power_motor){//similar a la funcion avanzar pero en retroceso
	motor[rightMotor] = power_motor*-1;
	motor[leftMotor] = power_motor*-1;
}

void rotar_derecha(int grados, int power_motor){//Funcion para el giro del robot hacia la derecha

	moveMotorTarget(leftMotor, grados, power_motor);
	moveMotorTarget(rightMotor,grados*-1,power_motor*-1);
	waitUntilMotorStop(rightMotor);
	waitUntilMotorStop(leftMotor);
}

task main(){//funcion principal
while(true){

		if (color_Black()&&(estadocolor!=colorBlack)){// se define que si el robot vee un color se alejara

			brazoArriba();
			avanzar(-10);
			wait1Msec(20);
			rotar_derecha(120,40);
			estadocolor = colorBlack;
		}else{
		//si ve un color negro y no detecta nada, el robot se alejara y tomara otro rumbo



			avanzar(6);

		}
		if (color_Green()&&(estadocolor!=colorGreen)){ // se define que si el robot detecta un color verde, sabra que es entra/salida y lo mostrara por pantalla
			displayCenteredBigTextLine(3,"ENTRADA/SALIDA");
			sleep(1000);
			displayCenteredBigTextLine(3," ");
			estadocolor = colorGreen;
		}

		if (color_Red()&&(estadocolor!=colorRed)){ // se define que si el robot detecta un color red, sabra que es nuestro color y lo mostrara por pantalla
			displayCenteredBigTextLine(5,"Color nuestro");
			sleep(1000);
			displayCenteredBigTextLine(5," ");
			estadocolor = colorRed;
		}

			if (color_white()&&(estadocolor!=colorWhite)){ // se define que si el robot detecta el color blanco, retrosedera, marca y avanzara
			avanzar(-20);
			sleep(300);
			brazoAbajo();
			avanzar(5);

			sleep(1200); //duerme la lectura de lineas
			brazoArriba();
			estadocolor = colorWhite;
		}
		if (color_Blue()&&(estadocolor!=colorBlue)){ // se define que si el robot detecta un color azul, sabra que es el color oponente y lo mostrara por pantalla
			displayCenteredBigTextLine(2,"Color oponente");
			sleep(1000);
			displayCenteredBigTextLine(2," ");
			continue;
			estadocolor = colorBlue;

		}

	}





}
