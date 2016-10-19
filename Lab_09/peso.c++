double calc_peso(arv *Arv){
  double e,d;

  //se a arvore for nula, as arestas n possuem peso, assim retornamos 0
  if(Arv == NULL)
    return 0;

    else if(Arv->left == NULL)
      return Arv->p_right + calc_peso(Arv->right);

      else if(Arv->right == NULL)
        return Arv->p_left + calc_peso(Arv->left);

  e = Arv->p_left + calc_peso(Arv->left);
  d = Arv->p_right + calc_peso(Arv->right);

  return (e > d) ? e : d;

}
