package feuTricolore;

import java.awt.Color;
import java.util.Iterator;

public class Main {

	public static void main(String[] args) {
	
		FeuTricolore FT = new FeuTricolore();
		Iterator<Color> it = FT.iterator();
		
		while( it.hasNext() ){
			System.out.println(it.next());
		}
	}
}
