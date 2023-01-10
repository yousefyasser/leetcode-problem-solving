import java.util.ArrayList;

public class Twitter {
    ArrayList<ArrayList<Integer>> following;
    ArrayList<ArrayList<Integer>> tweets;

    public Twitter() {
        following = new ArrayList<>();
        tweets = new ArrayList<>();
    }
    
    public void postTweet(int userId, int tweetId) {
        ArrayList<Integer> tweet = new ArrayList<>();
        tweet.add(userId);
        tweet.add(tweetId);
        tweets.add(0,tweet);
    }
    
    public ArrayList<Integer> getNewsFeed(int userId) {
        ArrayList<Integer> userTweets = new ArrayList<>();
        ArrayList<Integer> followsWho = getFollowers(userId);
        int userFollowers = followsWho.remove(0);

        for(int i = 0; i < tweets.size() && userTweets.size() < 10; i++){
            if((tweets.get(i).get(0) == userId)){
                userTweets.add(tweets.get(i).get(1));
            }
            for(int j = 0; j < userFollowers && userTweets.size() < 10; j++){
                if(tweets.get(i).get(0) == followsWho.get(j)){
                    userTweets.add(tweets.get(i).get(1));
                }
            }
        }
        return userTweets;
    }
    
    private ArrayList<Integer> getFollowers(int userId){
        int userFollowers = 0;
        ArrayList<Integer> followsWho = new ArrayList<>();

        for(int i = 0; i < following.size(); i++){
            if(following.get(i).get(0) == userId){
                followsWho.add(following.get(i).get(1));
                userFollowers++;
            }
        }
        followsWho.add(0, userFollowers);
        return followsWho;
    }

    public void follow(int followerId, int followeeId) {
        if(!findFollower(followerId, followeeId)){
            ArrayList<Integer> follow = new ArrayList<>();
            follow.add(followerId);
            follow.add(followeeId);
            following.add(follow);
        }
    }
    
    private boolean findFollower(int followerId, int followeeId){
        for(int i = 0; i < following.size(); i++){
            if(following.get(i).get(0) == followerId && following.get(i).get(1) == followeeId)
                return true;
        }
        return false;
    }
    
    public void unfollow(int followerId, int followeeId) {
        for(int i = 0; i < following.size(); i++){
            if((following.get(i).get(0) == followerId && following.get(i).get(1) == followeeId)){
                following.remove(i);
                return;
            }
        }
    }
}