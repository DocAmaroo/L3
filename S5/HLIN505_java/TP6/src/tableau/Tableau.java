package tableau;

public class Tableau <A extends Comparable <A>>{

	private A T[];
	
	public Tableau(A T[]){
		this.T = T; // on fait une recopie superficielle
	}
	
	public void triBulles(){
		int i = T.length - 2;
		boolean ech = true;
		while( i >= 2 && ech){
			ech = false;
			for( int j=0; j <= i; j++){
				if( T[j].compareTo(T[j+1]) > 0 ){
					A aux = T[j];
					T[j] = T[j+1];
					T[j+1] = aux;
					ech = true;
				}
			}
		i--;
		}
	}
	
	public void affiche(){
		for( int i = 0; i < T.length; i++ ){
			System.out.println(T[i] + " ");
		}
		System.out.println();
	}
}
