#include <Arduino_FreeRTOS.h>

void Task_PSX(void *param);
void Task_Print2(void *param);


TaskHandle_t Task_Handle1;
TaskHandle_t Task_Handle2;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  
//Prioritas tertinggi, itu akan dijalankan terlebih dalu
xTaskCreate(Task_LED,"Task1",100,NULL,1,&Task_Handle1);
xTaskCreate(Task_Print2,"Task2",100,NULL,2,&Task_Handle2);
}


void loop() {
//Dead Loop
}

void Task_LED(void *param)
{
  (void)param;

  while(1)
    {
        digitalWrite(13, HIGH);
           vTaskDelay(1000/portTICK_PERIOD_MS);
        digitalWrite(13, LOW);
           vTaskDelay(1000/portTICK_PERIOD_MS);
    }
  }           

  void Task_Print2(void *param)
{
  (void)param;

  while(1)
  {
    Serial.println("Hello My Name is Ichal");
    vTaskDelay(1000/portTICK_PERIOD_MS);
    }
  }
