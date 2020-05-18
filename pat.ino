////PUBLISHERS CODE/////
int boardLed = D7;

void blink()
{
    
    digitalWrite(boardLed, HIGH);
    delay(100);
    digitalWrite(boardLed, LOW);
    delay(100);


    
}
void setup() {
    pinMode(boardLed,OUTPUT);

}
void loop() {
    //blink an led on publishers system when the event is published
     blink();
    

    //publish an event with unique name and message
    Particle.publish("Navdeep","pat");
    delay(10000);
}

///////SUBSCRIBERS CODE////////

int led = A5;

void setup() {
    // Our LED pin is output (lighting up the LED)
    pinMode(led,OUTPUT); 
    // Here we are going to subscribe to your buddy's event using Particle.subscribe and event occurs i.e., Blink.............
    Particle.subscribe("Navdeep", Blink);
}
void loop() {
}

void blink()
{
    digitalWrite(led,HIGH);
    delay(250);
    digitalWrite(led,LOW);
    delay(250);
}

void Blink(const char *event, const char *data)//blinking the led just once for a quick pat
{
    
    blink();
    
}
