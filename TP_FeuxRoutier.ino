#include <Servo.h>

// Définition des broches pour les feux de circulation
const int ROUGE_NS = 2;
const int JAUNE_NS = 3;
const int VERT_NS = 4;
const int ROUGE_EO = 5;
const int JAUNE_EO = 6;
const int VERT_EO = 7;

// Définition de la broche du servo moteur
const int BROCHE_SERVO = 8;

// Définition des broches des capteurs
const int CAPTEUR1 = 9;
const int CAPTEUR2 = 10;

// Définition de la broche de la LED
const int BROCHE_LED = 11;

// Définition des durées de phase
const long DUREE_PHASE1 = 30000; // Phase 1 : Feux nord-sud vert, feux est-ouest rouge
const long DUREE_PHASE2 = 3000;  // Phase 2 : Feux nord-sud jaune, feux est-ouest jaune
const long DUREE_PHASE3 = 30000; // Phase 3 : Feux nord-sud rouge, feux est-ouest vert
const long DUREE_PHASE4 = 3000;  // Phase 4 : Feux nord-sud jaune, feux est-ouest jaune

Servo servo;

void setup() {
  // Initialisation des broches de sortie
  pinMode(ROUGE_NS, OUTPUT);
  pinMode(JAUNE_NS, OUTPUT);
  pinMode(VERT_NS, OUTPUT);
  pinMode(ROUGE_EO, OUTPUT);
  pinMode(JAUNE_EO, OUTPUT);
  pinMode(VERT_EO, OUTPUT);
  pinMode(BROCHE_LED, OUTPUT);

  // Initialisation des broches des capteurs
  pinMode(CAPTEUR1, INPUT);
  pinMode(CAPTEUR2, INPUT);

  // Initialisation du servo moteur
  servo.attach(BROCHE_SERVO);
}

void loop() {
  // Vérification de l'état des capteurs
  bool capteur1_actif = digitalRead(CAPTEUR1) == HIGH;
  bool capteur2_actif = digitalRead(CAPTEUR2) == HIGH;

  // Allumage de la LED si un des capteurs est activé
  digitalWrite(BROCHE_LED, capteur1_actif || capteur2_actif);

  // Phase 1 : Feux nord-sud vert, feux est-ouest rouge, servo à 0°
  digitalWrite(ROUGE_NS, LOW);
  digitalWrite(JAUNE_NS, LOW);
  digitalWrite(VERT_NS, HIGH);
  digitalWrite(ROUGE_EO, HIGH);
  digitalWrite(JAUNE_EO, LOW);
  digitalWrite(VERT_EO, LOW);
  servo.write(0);
  delay(DUREE_PHASE1);

  // Phase 2 : Feux nord-sud jaune, feux est-ouest jaune
  digitalWrite(ROUGE_NS, LOW);
  digitalWrite(JAUNE_NS, HIGH);
  digitalWrite(VERT_NS, LOW);
  digitalWrite(ROUGE_EO, LOW);
  digitalWrite(JAUNE_EO, HIGH);
  digitalWrite(VERT_EO, LOW);
  delay(DUREE_PHASE2);

  // Phase 3 : Feux nord-sud rouge, feux est-ouest vert, servo à 180°
  digitalWrite(ROUGE_NS, HIGH);
  digitalWrite(JAUNE_NS, LOW);
  digitalWrite(VERT_NS, LOW);
  digitalWrite(ROUGE_EO, LOW);
  digitalWrite(JAUNE_EO, LOW);
  digitalWrite(VERT_EO, HIGH);
  servo.write(180);
  delay(DUREE_PHASE3);

  // Phase 4 : Feux nord-sud jaune, feux est-ouest jaune
  digitalWrite(ROUGE_NS, LOW);
  digitalWrite(JAUNE_NS, HIGH);
  digitalWrite(VERT_NS, LOW);
  digitalWrite(ROUGE_EO, LOW);
  digitalWrite(JAUNE_EO, HIGH);
  digitalWrite(VERT_EO, LOW);
  delay(DUREE_PHASE4);
}
