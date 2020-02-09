package salaire;

import java.util.ArrayList;
import java.util.Iterator;

public class IterableFeuilleSalaire implements Iterator<Object> {
	
	private ArrayList<Object> list;

	private int cursor = 0;
	
	public IterableFeuilleSalaire(ArrayList<Object> list){
		this.list = new ArrayList<Object>();
		this.list = list;
	}
	
	@Override
	public boolean hasNext(){
		return cursor < 6;
	}
	
	@Override
	public Object next(){
		Object res = "";
		if( hasNext() ){
			res = list.get(cursor);
		}
		cursor++;
		return res;
	}
	
	@Override
	public void remove(){
		throw new UnsupportedOperationException();
	}
}
