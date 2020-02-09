package feuTricolore;

import java.awt.Color;
import java.util.Iterator;

public class Main {

	public static void main(String[] args) throws InterruptedException {
	
		FeuTricolore FT = new FeuTricolore();
		Iterator<Color> it = FT.iterator();
		
		System.out.println("Attention par contre c'est une boucle infinie hein !");
		while( it.hasNext() ){
			System.out.println(it.next());
			Thread.sleep(1000);
		}
	}
}
