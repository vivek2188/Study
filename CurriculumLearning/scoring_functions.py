def scoring_function(alpha, score, frame_distance):
    '''
        alpha: Controls the contribution of score and frame_distance in Scoring Function
        score: Normalised score of (exemplar, candidate)==(z, x) pair from the tracker
        frame_distance: Normalised frame distance between z and x
    '''
    return score + alpha * (frame_distance - score) # Simplified form of: (1-alpha) * score + alpha * frame_distance

if __name__=='__main__':
    rank = scoring_function(0.6, 0.7, 0.8)
    print('Rank: {}'.format(rank))
