import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Statistics
 */
@WebServlet("/Statistics")
public class Statistics extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Statistics() {
        super();
        // TODO Auto-generated constructor stub
    }
    
    
    protected void service(HttpServletRequest request, HttpServletResponse response)
        	throws ServletException, IOException {
    	

    	PrintWriter out = response.getWriter();

    	Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		String json = "";
		try {
			conn = DriverManager.getConnection("//insert jdbc here");
			ps = conn.prepareStatement("SELECT compute_time, address, received_time, result FROM hashes");
			rs = ps.executeQuery();

			//initialize lists of data
			ArrayList<String> computetime, addr, receivedtime, result;
			computetime = new ArrayList<String>();
			addr = new ArrayList<String>();
			receivedtime = new ArrayList<String>();
			result = new ArrayList<String>();

			//fill lists
			while(rs.next()) {
				String c = Integer.toString(rs.getInt("compute_time"));
				computetime.add(c);
				String a = rs.getString("address");
				addr.add(a);
				String r = TimeStamp.toString(rs.getTimeStamp("received_time"));
				receivedtime.add(r);
				String re = rs.getString("result");
				result.add(re);
			}

			//brute force convert to json string
			String json += "{";
			
			json += "\"compute_time\":[";
			for(int i = 0; i < computetime.size(); i++) {
				json += "\"";
				json += computetime.get(i);
				json += "\"";
				if(i != computetime.size() -1) {
					json += ",";
				}
			}
			json += "],";

			json += "\"address\":[";
			for(int i = 0; i < addr.size(); i++) {
				json += "\"";
				json += addr.get(i);
				json += "\"";
				if(i != addr.size() -1) {
					json += ",";
				}
			}
			json += "],";

			json += "\"received_time\":[";
			for(int i = 0; i < receivedtime.size(); i++) {
				json += "\"";
				json += receivedtime.get(i);
				json += "\"";
				if(i != receivedtime.size() -1) {
					json += ",";
				}
			}
			json += "],";

			json += "\"result\":[";
			for(int i = 0; i < result.size(); i++) {
				json += "\"";
				json += result.get(i);
				json += "\"";
				if(i != result.size() -1) {
					json += ",";
				}
			}
			json += "]}";
		}
		catch(SQLException sqle) {
			System.out.println(sqle.getMessage());
		}
		finally {
			try {
				if(rs != null) {
					rs.close();
				}
				if(ps != null) {
					ps.close();
				}
				if(conn != null) {
					conn.close();
				}
			}
			catch (SQLException sqle) {
				System.out.println(sqle.getMessage());
			}
		}
	
    	out.write(json);
    	out.flush();
    	out.close();
    }
    
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
