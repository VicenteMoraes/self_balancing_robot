// Rotina para repetir parte do codigo a cada X milisegundos            creditos: @pinuct - Munique, Alemanha
#define runEvery(t) for (static long _lasttime;\
                         (uint16_t)((uint16_t)millis() - _lasttime) >= (t);\
                         _lasttime += (t))

uint32_t timer;
double Angulo;
double Saida_PID;

void setup(){

  Serial.begin(9600);
  inicializar_MPU();
  setSetPoint(0);
  gyro_Bias();
  
}

void loop(){

  runEvery(10){
    
   Angulo = 0.98 * (calcular_GyroAng()) + 0.02 * calcular_AccelAng();

   Serial.print(calcular_GyroAng());
   Serial.print(" ");
   Serial.print(Angulo);
   Serial.print(" ");
   Serial.println(calcular_AccelAng());
   

   Saida_PID = calcular_PID(Angulo);

   Saida_motores(Saida_PID);
  }
   
  
}

