package dijkstra;

import java.util.LinkedList;
import java.util.List;

public class Node {
	private String name;
	private boolean visited;
	// Each node contains a list of its own neighbours
	private List<Edge> edges;
	
	public Node(String name) {
		this.name = name;
		this.visited = false;
		this.edges = new LinkedList<>();
	}
	
	public String getName() {
		return name;
	}
	
	public List<Edge> getEdges() {
		return edges;
	}
	
	public boolean isVisited() {
		return visited;
	}
	
	public void visit() {
		visited = true;
	}
	
	public void unvisit() {
		visited = false;
	}
}
