#ifndef CYAN_ERROR_H
#define CYAN_ERROR_H


#include "cyan/common/config.h"

// Codes erreur utilisés pour le retour des fonctions
//
// Ici, j'ai choisi de ne pas utiliser de type enum afin
// de ne pas polluer l'espace de nommage et garder ca le
// plus simple possible ... KISS !

// Convention :
//
// Toutes les fonctions, a l'exception des constructeurs 
// et des destructeurs, doivent renvoyer un code erreur.
// 
// Les retours positifs sont reservés à des résultats de calcul
// Les codes erreurs doivent être négatifs
//

#define ERR_OK              0 
#define ERR_MALLOC         -1
#define ERR_NULL           -2
#define ERR_INVALID_ARG    -3

#if CYAN_CFG_VERBOSE_ERRORS
    #define CYAN_ERROR(ERROR_CODE) \
        fprintf(stderr, "Cyan Error: \t %s:%d %s\n", __FILE__, __LINE__, error_get_text( ERROR_CODE ) ) 
#else
    #define CYAN_ERROR(ERROR_CODE) 
#endif

const char* error_get_text ( int error_code ) ;

#endif