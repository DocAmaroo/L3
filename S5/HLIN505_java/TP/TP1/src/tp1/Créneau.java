package tp1;

public class Créneau {
	private JourSemaine jour;
	private HeureSimple hDeb;
	private HeureSimple hFin;
	
	
	public Créneau(JourSemaine jour, HeureSimple hDeb, HeureSimple hFin) {
		this.jour = jour;
		this.hDeb = hDeb;
		this.hFin = hFin;
	}
	
	public boolean estInclusDans(Créneau c){
		boolean res = false;
		if ( this.jour == c.jour ){
			if ( this.hDeb.getHeure() >= c.hDeb.getHeure() && this.hDeb.getHeure() <= c.hFin.getHeure()){
				if( this.hFin.getHeure() <= c.hFin.getHeure()){
					if ( this.hDeb.getMinute() >= c.hDeb.getMinute() && this.hFin.getMinute() <= c.hFin.getMinute()){
						res = true;
					}
				}
			}
		}
		return res;
	}
	
	public int getHDebmin(Créneau c1, Créneau c2){
		
		int hDebC1 = c1.hDeb.getHeure();
		int hFinC1 = c1.hFin.getHeure();
		int hDebC2 = c2.hDeb.getHeure();
		
		if ( hDebC1 == hDebC2){
			if ( c1.hDeb.getMinute() < c2.hDeb.getMinute()) return 1;
			else return 2;
		}
		
		if ( hDebC1 < hDebC2 && hDebC2 <= hFinC1) return 1;
		else if ( hDebC1 >= hDebC2 && hDebC2 > hFinC1) return 2;
		else return 0;
		
	}
	
	public int getHFinmax(Créneau c1, Créneau c2){
		
		int hFinC1 = c1.hFin.getHeure();
		int hDebC2 = c2.hDeb.getHeure();
		int hFinC2 = c2.hFin.getHeure();
		
		if ( hFinC1 == hFinC2){
			if ( c1.hFin.getMinute() < c2.hFin.getMinute()) return 2;
			else return 1;
		}
		
		if ( hFinC1 < hFinC2 && hFinC1 >= hDebC2) return 2;
		else if ( hFinC1 >= hFinC2 && hFinC1 < hDebC2) return 1;
		else return 0;
	}
	
	public boolean chevauche(Créneau c){
		boolean res = false;
		if ( getHDebmin(this, c) != getHFinmax(this, c)){
			res = true;
		}
		
		return res;
	}
	@Override
	public String toString() {
		return jour + " " + hDeb + " - " + hFin;
	}
	
	
}
