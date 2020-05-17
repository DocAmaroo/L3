package tp1;

public class Créneau2 {
	
	public class HeureSimple2 {
		private int heure;
		private int minute;
		
		private static final int granulariteMinutes=5;
		private static final int heureMax=22;
		private static final int heureMin=7;
		
		
		public int getHeure() {
			return heure;
		}

		public int getMinute() {
			return minute;
		}

		public HeureSimple2(int heure, int minute) {
			this.heure = heure;
			this.minute = minute;
			if ( !checkHeure() || !checkMinute()){
				this.heure = -1;
				this.minute = -1;
			}
		}

		public boolean checkHeure(){
			boolean res = true;
			if (heure >= heureMax && heure <= heureMin || heure > 24 || heure < 0){
				res = false;
			}
			return res;
		}

		public boolean checkMinute(){
			boolean res = minute%granulariteMinutes==0;
			if ( heure == heureMax && minute != 0 || minute > 60 || minute < 0) res = false;
			return res;
		}
		
		public String formatHeure(){
			if ( heure < 10 ){
				return "0"+heure;
			}
			else
				return heure+"";
		}
		
		public String formatMinute(){
			if ( minute < 10 ){
				return "0"+minute;
			}
			else
				return minute+"";
		}
		
		@Override
		public String toString() {
			return heure==-1 ? "ERROR" : minute==-1 ? "ERROR" : formatHeure() + ":" + formatMinute();
		}

		
	}
	
	private JourSemaine jour;
	private HeureSimple2 hDeb;
	private HeureSimple2 hFin;
	
	public Créneau2(JourSemaine jour, int h1, int m1, int h2, int m2) {
		this.jour = jour;
		this.hDeb = new HeureSimple2(h1, m1);
		this.hFin = new HeureSimple2(h2, m2);

	}
	
	public boolean estInclusDans(Créneau2 c){
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
	
	public int getHDebmin(Créneau2 c1, Créneau2 c2){
		
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
	
	public int getHFinmax(Créneau2 c1, Créneau2 c2){
		
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
	
	public boolean chevauche(Créneau2 c){
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
