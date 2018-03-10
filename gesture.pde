import de.voidplus.leapmotion.*;
import processing.serial.*;

Serial myPort;
LeapMotion leap;
PVector iPos=null;
PVector tPos=null;
PVector mPos=null;
PVector rPos=null;
PVector pPos=null;
float val =0;
float sval =0;
String s;
void setup(){
  size(1280,800,P2D);
  
  String portName = Serial.list()[2];
  myPort = new Serial(this, portName, 9600);
  
  leap = new LeapMotion(this);
}

void draw(){
  background(0);
  
  iPos=null;
  tPos=null;
  mPos=null;
  rPos=null;
  pPos=null;
  for(Hand hand : leap.getHands()){
    iPos = hand.getIndexFinger().getPosition();
    tPos = hand.getThumb().getPosition();
    mPos = hand.getMiddleFinger().getPosition();
    rPos = hand.getRingFinger().getPosition();
    pPos = hand.getPinkyFinger().getPosition();
  }
  
  if(iPos!=null){
    if(iPos.y>height/2){
     val = constrain(map(iPos.x,0,1100,0,59),0,59);
    }
    s = ""+int(val);
    sval = constrain(map(iPos.y,0,700,0,255),0,255);
    s = s+","+int(sval)+"\n"; 
    delay(80);
    
    myPort.write(s);
    
    println(s);
    ellipse(iPos.x,iPos.y,iPos.z,iPos.z);
    ellipse(tPos.x,tPos.y,tPos.z,tPos.z);
    ellipse(mPos.x,mPos.y,mPos.z,mPos.z);
    ellipse(rPos.x,rPos.y,rPos.z,rPos.z);
    ellipse(pPos.x,pPos.y,pPos.z,pPos.z);
  }
}