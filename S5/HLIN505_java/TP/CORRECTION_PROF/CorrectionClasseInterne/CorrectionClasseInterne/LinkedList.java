package classesInternes;

public class LinkedList {
	private Node root = null;

	public class Node {
		private int valeur;
		private Node next;

		//   ...
		private Node (int i){
			valeur=i;
		}
		public void setAsRoot() {
			root = this;
		}

		private void incr(){
			valeur++;
			if (next!=null){
				next.incr();
			}
		}
	}

	public Node getRoot() {
		return root;
	}

	public void setRoot( Node node ) {
		root = node;
	}
	public void incrAllValues(){
		root.incr();
	}

	public void print(){
		Node n=root;
		while (n!=null){
			System.out.println(n.valeur);
			n=n.next;
		}
	}
	public void ajoutTete(int i){
		Node tete=new Node(i);
		tete.next=root;
		root=tete;
		assert true;
	}
	
	public static void main(String[] args){
		LinkedList l=new LinkedList();
		l.ajoutTete(2);
		l.ajoutTete(3);
		l.print();
	}
}

