package Exercice1_Interface;

import java.io.IOException;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.StringTokenizer;



public class Song extends AbstractAudioElement {
	private String singer;
	private int duration;

	//@Override
	public int getDuration() {
		return duration;
	}
	public Song(int duration, String title, String fileLocation, String singer) throws IncorrectFileNameException {
		super(title, fileLocation);
		this.singer = singer;
		this.duration=duration;
		if (!getFile().exists()){
			throw new IncorrectFileNameException(fileLocation);
		}
	}
	@Override
	public String toString() {
		String result="S|";
		result+=duration+"|"+getTitle()+"|"+getFileLocation()+"|"+singer;	
		return result;
	}
	
	@Override
	public long getSize() throws IOException{
		return getFile().length();
	}

	@ToDo (type = TypeTache.tester, numeroVersion = 1, duree = 0.1 )
	public static Song fromString(String s) throws IncorrectFileNameException{
		StringTokenizer st=new StringTokenizer(s, "|");
		st.nextToken(); //pas besoin du S, il faudrait vérifier cohérence 
		int duration=Integer.valueOf(st.nextToken());
		String title=st.nextToken();
		String file=st.nextToken();
		String singer=st.nextToken();
		return new Song(duration, title, file, singer);
	}
	
	/*
	@Override
	public String getFileLocation(boolean b){
		return null;
	}
	*/
	
	@Override
	public String getFileLocation(){
		return null;
	}
	
	@Override
	public boolean isSong(){ return true;} 
	@Override
	public  boolean isPlayList(){ return false;} 
}
