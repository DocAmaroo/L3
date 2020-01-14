package fileAttente;

import java.util.ArrayList;

public class FileAttente<A>{
	
	protected ArrayList<A> contenu;
	
	public FileAttente(){
		contenu=new ArrayList<A>();
	}
	
	public void entre(A p){
		contenu.add(p);
	}
	
	public A sort(){
		
		A p=null;
		
		if (!contenu.isEmpty()){
			p=contenu.get(0);
           contenu.remove(0);
        }
		
		return p;
	}
	
	public boolean estVide(){
		return contenu.isEmpty();
	}
	
	public String toString(){
		return ""+contenu;
	}
	
	public ArrayList<A> getContenu(){
		return contenu;
	}
}

