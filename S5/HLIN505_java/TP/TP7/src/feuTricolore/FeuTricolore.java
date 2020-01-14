package feuTricolore;

import java.awt.Color;
import java.util.ArrayList;

public class FeuTricolore implements Iterable<Color>{
	
	private ArrayList<Color> tabColor;
	
	public FeuTricolore(){
		this.tabColor = new ArrayList<Color>();
		this.tabColor.add(Color.red);
		this.tabColor.add(Color.orange);
		this.tabColor.add(Color.green);
	}
	
	@Override
	public IteratorColor iterator(){
		return new IteratorColor(tabColor);
	}
	
}
