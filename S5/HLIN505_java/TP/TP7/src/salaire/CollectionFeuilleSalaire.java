package salaire;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.stream.Collectors;

public class CollectionFeuilleSalaire {
	
	private ArrayList<FeuilleSalaire> list;
	private int cursor = 0;
	
	public CollectionFeuilleSalaire(ArrayList<FeuilleSalaire> list){
		this.list = list;
	}
	
	public FeuilleSalaire getFeuilleSalaire(){
		return list.get(cursor);
	}
	
	public void print(){
		list.stream().forEach( l -> System.out.println(l.toString()));
	}
	
	public void printFE(){
		list.forEach( l -> System.out.println(l.toString()));
	}
	
	public void tri1(){
		FeuilleSalaire temp = new FeuilleSalaire();
		for ( int i=0; i < list.size()-1; i++){
			for (int j=i; j < list.size()-1; j++){
				if ( list.get(j).getNbHeurePaye() < list.get(j+1).getNbHeurePaye() ){
					temp = list.get(j);
					list.set(j, list.get(j+1));
					list.set(j+1, temp);
				}
			}
		}
	}
	
	public void tri3(){
		ArrayList<FeuilleSalaire> temp = (ArrayList<FeuilleSalaire>)list.stream()
		.sorted(Comparator.comparingInt( FS -> FS.getNbHeurePaye() ))
		.collect(Collectors.toList());
		
		CollectionFeuilleSalaire CFS = new CollectionFeuilleSalaire(temp);
		CFS.print();
	}
}
