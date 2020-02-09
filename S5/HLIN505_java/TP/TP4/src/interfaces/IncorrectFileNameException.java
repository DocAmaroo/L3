package interfaces;

public class IncorrectFileNameException extends Exception {
	String fileName;
	
	public IncorrectFileNameException(String errorMessage){
		super(errorMessage);
		this.fileName = errorMessage;
	}
	
	public String getFileName(){
		return fileName;
	}
}
