package pile;

public interface IPile<A>{
	boolean estVide();
	void empile(A a);
	A depile(); // retourne l'élément en sommet de pile et dépile
	int nbElements();
	A sommet(); // reteourne le sommet de pile mais ne le depile pas
}
