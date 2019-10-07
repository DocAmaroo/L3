package interfaces;

import java.io.IOException;

public interface IElementAudio {

	int getDuree();
	String getTitre();
	String getFileLocation();
	int getTaille() throws IOException;

}
