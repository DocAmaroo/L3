package Exercice1_Interface;

public class IncorrectFileNameException extends Exception {
	  String fileName;
	  
	  public IncorrectFileNameException(String fileName){
		  super(fileName);
		  this.fileName=fileName;
	  }
	  
	  public String getFileName(){
		  return fileName;
	  }
	}