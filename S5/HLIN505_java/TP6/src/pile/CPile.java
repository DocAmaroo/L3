package pile;

import java.util.LinkedList;

public class CPile<A> implements IPile<A>{
	private LinkedList<A> Pile;
	
	public CPile(){
		Pile = new LinkedList<A>();
	}
	
	public boolean estVide(){
		return Pile.isEmpty();
	}

	public void empile(A a) {
		Pile.add(a);
	}

	public A depile() {
		return Pile.removeLast();
	}

	public int nbElements() {
		return Pile.size();
	}

	public A sommet() {
		return Pile.getLast();
	}
}
