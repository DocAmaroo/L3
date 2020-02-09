package Exercice1_Interface;

import java.io.File;
import java.io.IOException;

public abstract class AbstractAudioElement implements ElementAudio {
	
	private String title;
	private String fileLocation;
	private File file;

	@Override
	public String getTitle() {
		
		return title;
	}

	@Override
	public String getFileLocation() {
		return fileLocation;
	}

	public AbstractAudioElement(String title, String fileLocation) {
		this.title = title;
		this.fileLocation = fileLocation;
		file=new File(fileLocation);
	}
	
	
	
	public File getFile(){
		return file;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public void setFileLocation(String fileLocation) {
		this.fileLocation = fileLocation;
	}

	

}
