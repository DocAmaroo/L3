package fileAttente;

public class FileAttentePrioritaire<A extends ElementAvecPriorite> extends FileAttente<A> {

	public FileAttentePrioritaire(){
		super();
	}
	
	@Override
	public void entre(A p){
		
		boolean ajout = false;
		int taille = getContenu().size();
		
		if (taille == 0){
			getContenu().add(p);
		}
		
		else {
			for( int i=0; i < taille; i++ ){
				if( p.priorite() < getContenu().get(i).priorite() ){
					getContenu().add(i, p);
					ajout = true;
					break;
				}
			}
			if ( !ajout ){
				getContenu().add(p);
			}
		}
	}
}

