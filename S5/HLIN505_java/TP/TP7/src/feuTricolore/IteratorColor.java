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
	
	@Override
	public boolean hasNext(){
		return cursor < 3;
	}
	
	@Override
	public Color next(){
		int temp = cursor;
		cursor++;
		if ( cursor == 3 ){
			cursor = 0;
		}
		return tabColor.get(temp);
	}
	
	@Override
	public void remove(){
		throw new UnsupportedOperationException();
	}
}
