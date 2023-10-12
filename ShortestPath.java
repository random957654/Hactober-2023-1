import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class DijkstraAlgorithm {
    private static final int INFINITY = Integer.MAX_VALUE;

    private int numVertices;
    private List<List<Edge>> adjacencyList;

    public DijkstraAlgorithm(int numVertices) {
        this.numVertices = numVertices;
        adjacencyList = new ArrayList<>(numVertices);
        for (int i = 0; i < numVertices; i++) {
            adjacencyList.add(new ArrayList<>());
        }
    }
    public void addEdge(int source, int destination, int weight) {
        Edge edge = new Edge(destination, weight);
        adjacencyList.get(source).add(edge);
    }
    public List<Integer> findShortestPath(int source, int destination) {
        int[] distances = new int[numVertices];
        int[] previous = new int[numVertices];
        PriorityQueue<Vertex> minHeap = new PriorityQueue<>(Comparator.comparingInt(v -> v.distance));

        Arrays.fill(distances, INFINITY);
        Arrays.fill(previous, -1);

        distances[source] = 0;
        minHeap.add(new Vertex(source, 0));

        while (!minHeap.isEmpty()) {
            Vertex current = minHeap.poll();

            if (current.vertex == destination) {
                break;
            }
            if (current.distance > distances[current.vertex]) {
                continue;
            }
            for (Edge edge : adjacencyList.get(current.vertex)) {
                int newDistance = distances[current.vertex] + edge.weight;

                if (newDistance < distances[edge.destination]) {
                    distances[edge.destination] = newDistance;
                    previous[edge.destination] = current.vertex;
                    minHeap.add(new Vertex(edge.destination, newDistance));
                }
            }
        }
        return buildPath(previous, destination);
    }
    private List<Integer> buildPath(int[] previous, int destination) {
        List<Integer> path = new ArrayList<>();
        while (destination != -1) {
            path.add(destination);
            destination = previous[destination];
        }
        Collections.reverse(path);
        return path;
    }
    private static class Edge {
        int destination;
        int weight;

        public Edge(int destination, int weight) {
            this.destination = destination;
            this.weight = weight;
        }
    }
    private static class Vertex {
        int vertex;
        int distance;

        public Vertex(int vertex, int distance) {
            this.vertex = vertex;
            this.distance = distance;
        }
    }
	public static void main(String[] args) {

		        int numVertices = 6;
		        DijkstraAlgorithm graph = new DijkstraAlgorithm(numVertices);

		        graph.addEdge(0, 1, 4);
		        graph.addEdge(0, 2, 2);
		        graph.addEdge(1, 2, 1);
		        graph.addEdge(1, 3, 5);
		        graph.addEdge(2, 3, 8);
		        graph.addEdge(2, 4, 10);
		        graph.addEdge(3, 4, 2);
		        graph.addEdge(3, 5, 6);
		        graph.addEdge(4, 5, 3);

		        int source = 0;
		        int destination = 5;
		        List<Integer> shortestPath = graph.findShortestPath(source, destination);

		        System.out.println("Shortest path from " + source + " to " + destination + ": " + shortestPath);
	}
}
