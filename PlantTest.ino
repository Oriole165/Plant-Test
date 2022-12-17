
const int AirValue = 520;   //you need to replace this value with Value_1
const int WaterValue = 260;  //you need to replace this value with Value_2
int intervals = (AirValue - WaterValue)/3;
int soilMoistureValue = 0;
void setup() {
  pinMode(8, OUTPUT);
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}
void loop() {
digitalWrite(8, LOW);
delay(5000);

soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
if(soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals))
{
  digitalWrite(8, LOW);
  Serial.println("Very Wet: ");
  Serial.print("Moisture Sensor Value: ");
  Serial.println(soilMoistureValue);
  
}
else if(soilMoistureValue > (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals))
{
  
  digitalWrite(8, LOW);
  Serial.println("Wet: ");
  Serial.print("Moisture Sensor Value: ");
  Serial.println(soilMoistureValue);
}
else if(soilMoistureValue < AirValue && soilMoistureValue > (AirValue - intervals))
{
  
  digitalWrite(8, HIGH);
  Serial.println("Dry: ");
  Serial.print("Moisture Sensor Value: ");
  Serial.println(soilMoistureValue);
}
Serial.println();

delay(10000);
}
