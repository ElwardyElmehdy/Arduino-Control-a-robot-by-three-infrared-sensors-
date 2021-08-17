#define IR1 13
#define IR2 12
#define IR3 11
#define M1A 10
#define M1R 9
#define M2A 8
#define M2R 7

void setup() {
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
  pinMode(M1A,OUTPUT);
  pinMode(M1R,OUTPUT);
  pinMode(M2A,OUTPUT);
  pinMode(M2R,OUTPUT);
  

}

enum{etat1,etat2,etat3,etat4,etat5};
int etat=etat1;
String capteur;
int etat_preced;




String IR(){
  
  Serial.println("entre IR");
  short tab[2];
  tab[0]=digitalRead(IR1);
  tab[1]=digitalRead(IR2);
  tab[2]=digitalRead(IR3);
  String I_R=String(tab[0])+String(tab[1])+String(tab[2]);
  return I_R;
}

void avancer(){
  if(etat_preced!=etat){
    arreter();
    delay(100);
    }
  digitalWrite(M1A,HIGH);
  digitalWrite(M2A,HIGH);
  digitalWrite(M1R,LOW);
  digitalWrite(M2R,LOW);
  etat_preced=etat1;
 
  
}

void reculer(){
  if(etat_preced!=etat){
    arreter();
    delay(100);
    }
    
  
  digitalWrite(M1A,LOW);
  digitalWrite(M2A,LOW);
  digitalWrite(M1R,HIGH);
  digitalWrite(M2R,HIGH);
  
  etat_preced=etat2;
}
void tourne_g(){
  if(etat_preced!=etat){
    arreter();
    delay(100);
    }
 
  
  digitalWrite(M1A,HIGH);
  digitalWrite(M2A,LOW);
  digitalWrite(M1R,LOW);
  digitalWrite(M2R,LOW);
  etat_preced=etat3;
}

void tourne_d(){
  if(etat_preced!=etat){
    arreter();
    delay(100);
    }
   
  digitalWrite(M1A,LOW);
  digitalWrite(M2A,HIGH);
  digitalWrite(M1R,LOW);
  digitalWrite(M2R,LOW);
etat_preced=etat4;
  
}
void tourne_gd_al(){
  if(etat_preced!=etat){
    arreter();
    delay(100);
    }
  
  int m=random(0,2);

  digitalWrite(M1A,m);
  digitalWrite(M2A,!m);
  digitalWrite(M1R,LOW);
  digitalWrite(M2R,LOW);
  
  etat_preced=etat5;
}


void arreter(){
  digitalWrite(M1A,LOW);
  digitalWrite(M2A,LOW);
  digitalWrite(M1R,LOW);
  digitalWrite(M2R,LOW);
}



void loop() {
 
capteur=IR();


switch(etat){
   
  case etat1:
  avancer();
  if(capteur=="000"){etat=etat1;}
  if(capteur=="101"||capteur=="111"){etat=etat2;}
  if(capteur=="011"||capteur=="001"){etat=etat3;}
  if(capteur=="110"||capteur=="100"){etat=etat4;}
  if(capteur=="010"){etat=etat5;}
  break;
  
   case etat2:
  reculer();
  if(capteur!="101"&&capteur!="111"){etat=etat1;}
  break;
  
   case etat3:
  tourne_g();
  if(capteur!="011"&&capteur!="001"){etat=etat1;}
  break;
  
 case etat4:
  tourne_d();
  if(capteur!="110"&&capteur!="100"){etat=etat1;}
  break;
  
   case etat5:
  tourne_gd_al();
  if(capteur!="010"){etat=etat1;}
  break;
  // put your main code here, to run repeatedly:

}

}
