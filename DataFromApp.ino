  /* include library */
  #include <ESP8266WiFi.h>
  
  /* define port */
  WiFiClient client;
  WiFiServer server(80);
  
  /* WIFI settings */
  const char* ssid = "Ashwathama";
  const char* password = "qwerty123";
  
  /* data received from application */
  String  data =""; 
  void setup()
  {
   
  
    /* start server communication 192.168.43.141*/
    server.begin();
    Serial.begin(115200);
  }
  
  void loop()
  {
      /* If the server available, run the "checkClient" function */  
      client = server.available();
      if (!client) return; 
      data = checkClient ();
  Serial.println(data);
  }
  
  String checkClient (void)
  {
    while(!client.available()) delay(1); 
    String request = client.readStringUntil('\r');
    request.remove(0, 5);
    request.remove(request.length()-9,9);
    return request;
  }
