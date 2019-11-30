packet ProjectServer;

public class HashAccept extends Thread {
	Connection conn;
	byte[] recvmsg;
	String recvip;

	private String toString(byte[] msg) {
		String str = "";

		int i = 0;
		while(msg[i] != 0) {
			str += (char)msg[i];
			i++;
		}

		return str;
	}

	public HashAccept(Connection conn, DatagramPacket recv) {
		this.conn = conn;
		this.recvmsg = recv.getData();
		this.recvip = recv.getSocketAddress().toString(); //might have to cast SocketAddress to InetSocketAddress

		this.start();
	}

	public void run() {
		try {
			String msg = toString(recv);
			String[] data = msg.split(" ");

			String result = data[0];
			int compute_time = Integer.parseInt(data[1]);

			try {
				//add info to database
				PreparedStatement ps = null;
				ps = conn.prepareStatement("INSERT INTO hashes (compute_time, address, result) VALUES (?,?,?)");
				ps.setInt(1, compute_time);
				ps.setString(2, recvip);
				ps.setString(3, result);
				ps.executeUpdate();
			}
			
			if(ps != null) {
				ps.close();
			}

		}
		catch (SQLException sqle) {
			System.out.println(sqle.getMessage());
		}
	}
}