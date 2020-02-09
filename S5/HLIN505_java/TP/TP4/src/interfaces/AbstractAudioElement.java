package interfaces;

import java.io.File;

public abstract class AbstractAudioElement implements IElementAudio {
	
	private String titre;
	private String fileLocation;
	private File f;
	
	public AbstractAudioElement(String titre, String fileLocation){
		this.titre = titre;
		this.fileLocation = fileLocation;
		f = new File(fileLocation);
	}
	
	public String getTitre(){
		return this.titre;
	}
	
	
	public String getFileLocation(){
		return this.fileLocation;
	}
	
	public File getFile(){
		return f;
	}
	
	public void setTitle(String titre){
		this.titre = titre;
	}
	
	public void setFileLocation(String fileLocation){
		this.fileLocation = fileLocation;
	}
}
