package salaire;

import java.util.ArrayList;

public class FeuilleSalaire implements Iterable<Object> {
	
	private ArrayList<Object> list;
	
	public FeuilleSalaire(){}
	public FeuilleSalaire(String employeur, String salarie, String convCollective, int nbHeurePaye, int prelevementFiscaux, int net) {
		this.list = new ArrayList<Object>();
		list.add(employeur);
		list.add(salarie);
		list.add(convCollective);
		list.add(nbHeurePaye);
		list.add(prelevementFiscaux);
		list.add(net);
	}
	
	public IterableFeuilleSalaire iterator(){
		return new IterableFeuilleSalaire(list);
	}
	

}
