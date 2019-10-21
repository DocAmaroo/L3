package feuTricolore;

import java.awt.Color;
import java.util.ArrayList;
import java.util.Iterator;

public class IteratorColor implements Iterator<Color> {
	
	private ArrayList<Color> tabColor;
	private int cursor = 0;
	
	public IteratorColor(ArrayList<Color> tabColor){
		this.tabColor = tabColor;
	}
	
	public boolean hasNext(){
		return cursor < 3;
	}
	
	public Color next(){
		cursor++;
		if ( cursor == 3 ){
			cursor = 0;
		}
		return tabColor.get(cursor);
	}
}
