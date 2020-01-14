package interfaces;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public abstract class SimplePlaylist extends AbstractAudioElement implements Playlist{
	
	private ArrayList<Song> list = new ArrayList<Song>();

	public SimplePlaylist(String titre, String fileLocation) throws IOException {
		super(titre, fileLocation);
		if( getFile().exists()){
			BufferedReader buffer = new BufferedReader(new FileReader(getFile()));
			String line = buffer.readLine();
			while(line != null){
				try{
					Song s = Song.fromString(line);
					list.add(s);
					
				}
			}
		}
	}

	
	public String toString(){
		String res = getTitre() + "\n";
		
		for( Song element : list){
			res += ""
		}
		
		return res;
	}
}
